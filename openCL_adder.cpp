#define CL_HPP_ENABLE_EXCEPTIONS 
#define CL_HPP_TARGET_OPENCL_VERSION 200 

#include <CL/opencl.hpp> 
#include <iostream> 
#include <vector> 
#include <memory> 
#include <algorithm> 

int main() {
    const size_t n = 100;
    std::vector<float> a(n, 1.0f);
    std::vector<float> b(n, 2.0f);
    std::vector<float> c(n, 0.0f);

    // Get available platforms 
    std::vector<cl::Platform> platforms;
    cl::Platform::get(&platforms);

    // Get available devices 
    std::vector<cl::Device> devices;
    platforms[0].getDevices(CL_DEVICE_TYPE_ALL, &devices);

    // Create a context and command queue 
    cl::Context context(devices);
    cl::CommandQueue queue(context, devices[0]);

    // Create buffers 
    cl::Buffer a_buf(context, CL_MEM_READ_ONLY, n * sizeof(float));
    cl::Buffer b_buf(context, CL_MEM_READ_ONLY, n * sizeof(float));
    cl::Buffer c_buf(context, CL_MEM_WRITE_ONLY, n * sizeof(float));

    // Copy data to buffers 
    queue.enqueueWriteBuffer(a_buf, CL_TRUE, 0, n * sizeof(float), a.data());
    queue.enqueueWriteBuffer(b_buf, CL_TRUE, 0, n * sizeof(float), b.data());

    // Create and build program 
    std::string kernel_code = R"( 
        __kernel void add_vectors(__global const float* a, 
                                   __global const float* b, 
                                   __global float* c) { 
            const int i = get_global_id(0); 
            c[i] = a[i] + b[i]; 
        } 
    )";

    cl::Program program(context, kernel_code);
    program.build(devices);

    // Create kernel 
    cl::Kernel kernel(program, "add_vectors");

    // Set kernel arguments 
    kernel.setArg(0, a_buf);
    kernel.setArg(1, b_buf);
    kernel.setArg(2, c_buf);

    // Enqueue kernel 
    queue.enqueueNDRangeKernel(kernel, cl::NullRange, cl::NDRange(n), cl::NullRange);

    // Copy results back to host 
    queue.enqueueReadBuffer(c_buf, CL_TRUE, 0, n * sizeof(float), c.data());

    // Print results 
    for (int i = 0; i < n; i++) {
        std::cout << c[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}
