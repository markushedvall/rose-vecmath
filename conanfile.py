from conans import ConanFile, CMake, tools


class RoseVecmathConan(ConanFile):
    name = "rose-vecmath"
    version = "0.0.0"
    license = "MIT OR Apache-2.0"
    url = "https://github.com/markushedvall/rose-vecmath"
    description = "A simple library for vector math with generic types"
    build_requires = "gtest/1.8.0@bincrafters/stable"
    settings = "os", "compiler", "arch", "build_type"
    generators = "cmake"
    exports_sources = "include/*", "test/*", "CMakeLists.txt"
    no_copy_source = True

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
        cmake.test()

    def package(self):
        self.copy("*.hpp")

    def package_id(self):
        self.info.header_only()
