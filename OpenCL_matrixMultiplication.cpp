#define CL_HPP_ENABLE_EXCEPTIONS
#define CL_HPP_TARGET_OPENCL_VERSION 200

#include <CL/opencl.hpp>
#include <iostream>
#include <vector>
#include <chrono>  // For measuring execution time

const int N = 200;  // Matrix size

void matrixMultiplyCPU(const std::vector<float>& A, const std::vector<float>& B, std::vector<float>& C) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            float sum = 0.0f;
            for (int k = 0; k < N; k++) {
                sum += A[i * N + k] * B[k * N + j];
            }
            C[i * N + j] = sum;
        }
    }
}

int main() {
    std::vector<float> A(N * N);  // Matrix A
    std::vector<float> B(N * N);  // Matrix B
    std::vector<float> C(N * N);  // Matrix C (Result)

    // Initialize input matrices A and B
    for (int i = 0; i < N * N; i++) {
        A[i] = static_cast<float>(i + 1);  // Example initialization
        B[i] = static_cast<float>(N * N - i);  // Example initialization
    }

    try {
        // Get available platforms
        std::vector<cl::Platform> platforms;
        cl::Platform::get(&platforms);

        // Get available devices
        std::vector<cl::Device> devices;
        platforms[0].getDevices(CL_DEVICE_TYPE_ALL, &devices);

        // Create a context and command queue
        cl::Context context(devices);
        cl::CommandQueue queue(context, devices[0]);

        // Create input and output buffers
        cl::Buffer bufferA(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, sizeof(float) * N * N, A);
        cl::Buffer bufferB(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, sizeof(float) * N * N, B);
        cl::Buffer bufferC(context, CL_MEM_WRITE_ONLY, sizeof(float) * N * N);

        // Read the OpenCL kernel code from a string
        std::string kernel_code = R"(
            __kernel void matrix_multiply(__global const float* A,
                                          __global const float* B,
                                          __global float* C,
                                          const int N) {
                int row = get_global_id(0);
                int col = get_global_id(1);
                float sum = 0.0f;

                for (int i = 0; i < N; i++) {
                    sum += A[row * N + i] * B[i * N + col];
                }

                C[row * N + col] = sum;
            }
        )";

        // Create the program and build it
        cl::Program program(context, kernel_code);
        program.build(devices);

        // Create the kernel
        cl::Kernel kernel(program, "matrix_multiply");

        // Set the kernel arguments
        kernel.setArg(0, bufferA);
        kernel.setArg(1, bufferB);
        kernel.setArg(2, bufferC);
        kernel.setArg(3, N);

        // Start measuring the OpenCL execution time
        auto startOpenCL = std::chrono::steady_clock::now();

        // Enqueue the OpenCL kernel for execution
        cl::NDRange globalSize(N, N);
        cl::NDRange localSize(1, 1);  // Use a 1x1 work-group size for simplicity
        queue.enqueueNDRangeKernel(kernel, cl::NullRange, globalSize, localSize);

        // Read the OpenCL result back to the host
        queue.enqueueReadBuffer(bufferC, CL_TRUE, 0, sizeof(float) * N * N, C);

        // Stop measuring the OpenCL execution time
        auto endOpenCL = std::chrono::steady_clock::now();
        auto durationOpenCL = std::chrono::duration_cast<std::chrono::microseconds>(endOpenCL - startOpenCL);

        // Print the result matrix from OpenCL
        std::cout << "Result Matrix from OpenCL:" << std::endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                std::cout << C[i * N + j] << " ";
            }
            std::cout << std::endl;
        }

        // Perform the matrix multiplication on the CPU
        std::vector<float> C_CPU(N * N);
        auto startCPU = std::chrono::steady_clock::now();
        matrixMultiplyCPU(A, B, C_CPU);
        auto endCPU = std::chrono::steady_clock::now();
        auto durationCPU = std::chrono::duration_cast<std::chrono::microseconds>(endCPU - startCPU);

        // Print the result matrix from the CPU
        std::cout << "\nResult Matrix from CPU:" << std::endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                std::cout << C_CPU[i * N + j] << " ";
            }
            std::cout << std::endl;
        }

        // Print the execution times
        std::cout << "\nExecution Time (OpenCL): " << durationOpenCL.count() << " microseconds" << std::endl;
        std::cout << "Execution Time (CPU): " << durationCPU.count() << " microseconds" << std::endl;

    }
    catch (cl::Error& err) {
        std::cerr << "OpenCL error: " << err.what() << " (" << err.err() << ")" << std::endl;
        return 1;
    }

    return 0;
}
