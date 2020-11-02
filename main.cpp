#include<iostream>
#include<mono/jit/jit.h>
#include<mono/metadata/mono-config.h>

int main(int argc, char* argv[]) {
    // Load the default Mono configuration file
    mono_config_parse(NULL);

    // Create a domain: each assembly is loaded and run in a MonoDomain
    MonoDomain *domain = mono_jit_init("startup.exe");

    // Open the executable, and run the Main method declared in the executable
    MonoAssembly *assembly = mono_domain_assembly_open(domain, "startup.exe");

    if (!assembly) {
        std::cerr << "Failed to load assembly" << std::endl;
        return EXIT_FAILURE;
    }

    mono_jit_exec(domain, assembly, argc, argv);

    return EXIT_SUCCESS;
}
