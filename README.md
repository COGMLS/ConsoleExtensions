# Console Extensions

## About this project:

This project was designed to make easier the process to use create or modified C++ console projects, providing support with a simplified ASCII controls and also unified interface controls for Operation System console functions. The Console Extensions is developed under the ISO C++ features, allowing an easy way to integrate it on any software, independent of the Operation System that is running.

**IMPORTANT:** The Console Extensions contain an collection of base libraries and headers to provide an equal behavior depending on the compiler. An good example is the Microsoft’s implementation on `std::exception` that is originally designed to be only a base class for other error handling classes. In `ErrorReport` library, that is an exception class that inherit from `std::exception` and provide the same behavior of Microsoft’s version, including an constructor to support to send an error message.

**NOTE:** *This project is under development and is not ready for production use. The actual libraries available are functional, but can receive modification that may broke your code*

**IMPORTANT:** (2024/09/27) ***The Console Extensions was redesigned to be compiled as a unified library. Reducing the dependency between each one and making easier to implement***

**IMPORTANT:** (2025/05/20) ***The Console Extensions project was published in GitHub (2025/05/20) and it's passing by a documentation revision. Some documentations are outdated or may not exist.***

## Projects:

| Library component | Version | Notes |
| ----------------- | ------- | ----- |
| ConsoleColorizedString | 1.6.13 |  |
| ConsoleExtControls | 0.5.0 |  |
| ConsoleExtInterface | 0.0.1 |  |
| ErrorReport | 0.0.1 |  |

## Credits:

Developed by Matheus L. Silvati

An license copy is available in [here](/LICENSE.txt)

## License:

MIT License

Copyright (c) 2022-2025 Matheus Lopes Silvati

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.