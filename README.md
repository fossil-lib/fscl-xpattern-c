# XPattern - `C`

The XPattern library offers a pragmatic approach to solving common programming challenges, providing a set of versatile patterns and solutions tailored to streamline development. Whether you're dealing with lazy evaluation, constraint handling, or implementing observer patterns, XPattern equips you with the tools you need to build robust and adaptable software solutions. XPattern serves as a foundational building block for your software endeavors, offering essential core functionalities that simplify the development process and provide a solid framework for your applications. With XPattern, you can create software that not only meets your current requirements but also remains flexible enough to adapt to the evolving needs of your projects.

## Prerequisites

Before getting started, make sure you have the following installed:

- **Meson Build System**: This project relies on Meson. If you don't have Meson installed, visit the official [Meson website](https://mesonbuild.com/Getting-meson.html) for installation instructions.

## Setting up, Compiling, Installing, and Running the Project

**Adding Dependency**:

Create a directory named subprojects in the root directory, next create a file named `fscl-xpattern-c.wrap` in the `subprojects` directory of your project with the following content:

   ```ini
   [wrap-git]
   url = https://github.com/fossil-lib/fscl-xpattern-c.git
   revision = main
   
   [provide]
   fscl-xpattern-c = fscl_xpattern_c_dep
   ```

**Integrate Dependency**:
   ```meson
   project('my_project', 'c')

   exe = executable('my_project', 'my_project.c',
       dependencies : dependency('fscl-xpattern-c')) # add this line

   test('basic', exe)
   ```

## Including the Demo and Running Tests

To run tests, you can use the following options when configuring the build:

- **Running Tests**: Add `-Dwith_test=enabled` when configuring the build.

Example:

```zsh
meson setup builddir -Dwith_test=enabled
```

## Contributing and Support

If you're interested in contributing to this project, encounter any issues, have questions, or would like to provide feedback, don't hesitate to open an issue or visit the [Fossil Logic Docs](https://fossillogic.com/the-docs) for more information.
