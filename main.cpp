#include<iostream>
#include<mono/jit/jit.h>
#include<mono/metadata/mono-config.h>

void func() {
    std::cout << "Hello from C++!" << std::endl;
}

int main(int argc, char* argv[]) {
    // Load the default Mono configuration file
    mono_config_parse(NULL);

    // Create a domain: each assembly is loaded and run in a MonoDomain
    MonoDomain *domain = mono_jit_init("Startup.exe");

    mono_add_internal_call("Startup::CPPFunc", (const void*) &func);

    // Open the executable, and run the Main method declared in the executable
    MonoAssembly *assembly = mono_domain_assembly_open(domain, "Startup.exe");

    if (!assembly) {
        std::cerr << "Failed to load assembly" << std::endl;
        return EXIT_FAILURE;
    }

    mono_jit_exec(domain, assembly, argc, argv);

    return EXIT_SUCCESS;
}
