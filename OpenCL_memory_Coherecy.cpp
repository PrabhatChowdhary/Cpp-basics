#define CL_HPP_ENABLE_EXCEPTIONS
#define CL_HPP_TARGET_OPENCL_VERSION 200

#include <CL/opencl.hpp>
#include <iostream>
#include <vector>

int main() {
    const size_t n = 10000;
    std::vector<int> data(n);

    // Initialize the data vector with an alternating pattern
    for (int i = 0; i < n; i++) {
        data[i] = i % 2; // Alternating pattern of 0 and 1
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

        // Create a buffer
        cl::Buffer buffer(context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR, n * sizeof(int), data.data());

        // Create a kernel
        std::string kernel_code = R"(
            __kernel void test_coherency(__global int* buffer) {
                int id = get_global_id(0);
                int value = buffer[id];
                int otherValue = buffer[(id + 1) % get_global_size(0)];
                buffer[id] = value + otherValue;
            }
        )";

        cl::Program program(context, kernel_code);
        program.build(devices);

        cl::Kernel kernel(program, "test_coherency");
        kernel.setArg(0, buffer);

        // Enqueue the kernel
        queue.enqueueNDRangeKernel(kernel, cl::NullRange, cl::NDRange(n), cl::NullRange);

        // Read the modified data back to the host
        queue.enqueueReadBuffer(buffer, CL_TRUE, 0, n * sizeof(int), data.data());

        // Verify the results and count passing and failing cases
        int passingCount = 0;
        int failingCount = 0;
        for (int i = 0; i < n; i++) {
            int expected = (i % 2) + ((i + 1) % 2); // Expected value after the read-modify-write operation
            if (data[i] == expected) {
                passingCount++;
            }
            else {
                failingCount++;
            }
        }

        // Print the passing and failing counts
        std::cout << "Passing Cases: " << passingCount << std::endl;
        std::cout << "Failing Cases: " << failingCount << std::endl;

    }
    catch (cl::Error& err) {
        std::cerr << "OpenCL error: " << err.what() << " (" << err.err() << ")" << std::endl;
        return 1;
    }

    return 0;
}
