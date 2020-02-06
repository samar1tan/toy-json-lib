# toy-json-lib
toy-level json parser &amp; generator

## Get Started: What's JSON?
- JavaScript Object Notation
  - A data-interchange format, originated from JS
- Features: lightweight, which is easy for
  - humans to read & write
  - machines to parse & generate
- Applications, e.g.,
  - Web API response format
  - Document-oriented database
  
## Project Overview
![overview](https://samaritan.cn/wp-content/uploads/2020/02/image-1.png)
- Components: standardized parser and generator
  - ECMA-404 The JSON Data Interchange Standard
  - e.g., recursive descent parser
- Language: C89
- LOC: approx. 4000

## Technical Details
- Roadmap
  - Parser: number --> string -> array --> object
  - Parser --> Generator
- Limited support
  - encoding, number type, correctness & efficiency, etc.
- As a so-called “high-level” programming experiment…
  - Test-driven Development
  - API design
  - cross-platform
  - unified code style
  - dev tools: CMake, Valgrind, Doxygen, etc.
  
## References
[1] Introducing JSON
https://json.org

[2] JSON from Wikipedia
https://en.wikipedia.org/wiki/JSON

[3] The Rise and Rise of JSON by Two-Bit History
https://twobithistory.org/2017/09/21/the-rise-and-rise-of-json.html

[4] 从零开始的JSON库教程 by Milo Yip
https://zhuanlan.zhihu.com/p/22457315 
