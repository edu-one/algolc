# Copyright (C) Denys Valchuk - All Rights Reserved
# ZHZhbGNodWtAZ21haWwuY29tCg==

from conan import ConanFile
from conan.tools.cmake import CMake, CMakeToolchain, CMakeDeps, cmake_layout


class AlgoConan(ConanFile):
    minimum_conan_version = '2.2'

    name = 'algolc'
    version = '0.0.1'
    license = "MIT"

    author = "Denys Valchuk <ZHZhbGNodWtAZ21haWwuY29tCg==>"
    url = "https://github.com/valden/algolc"
    description = "LeetCode solutions playground"
    topics = ("leetcode", "algolc", "playground")

    settings = "os", "compiler", "build_type", "arch"
    options = {"with_tests": [True, False]}
    default_options = {"with_tests": True}

    def layout(self):
        cmake_layout(self)

    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self)
        tc.variables["WITH_TESTS"] = bool(self.options.with_tests)
        tc.variables["CMAKE_BUILD_TYPE"] = "%s" % self.settings.build_type
        tc.generate()

    def requirements(self):
        if self.options.with_tests:
            self.requires("gtest/1.14.0")

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
        # project is small - so it is not an issue to run tests each build
        if self.options.with_tests:
            cmake.test()
