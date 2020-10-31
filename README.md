## Kavenegar API Client Written In Modern C++

[![Total alerts](https://img.shields.io/lgtm/alerts/g/Kambiz-Asadzadeh/Kavenegar.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/Kambiz-Asadzadeh/Kavenegar/alerts/)
[![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/Kambiz-Asadzadeh/Kavenegar.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/Kambiz-Asadzadeh/Kavenegar/context:cpp)
![Language iso: C++](https://img.shields.io/badge/C%2B%2B-17-blue)
![Version](https://img.shields.io/badge/Version-0.6-lightgrey)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20macOS%20%7C%20Linux%20%7C%20iOS%20%7C%20Android%20%7C%20Web-lightgrey)
![Dependencies](https://img.shields.io/badge/dependencies-Curl%20%7C%20RapidJson-yellow)

# <a href="http://kavenegar.com/rest.html">Kavenegar RESTful API Document</a>
If you need to future information about API document Please visit RESTful Document

## Installation
<p>
First of all, You need to make an account on Kavenegar from <a href="https://panel.kavenegar.com/Client/Membership/Register">Here</a>
</p>
<p>
After that you just need to pick API-KEY up from <a href="http://panel.kavenegar.com/Client/setting/index">My Account</a> section.
 
## Building

- You need CMake tool for building source code
- Get Curl & RapidJson [Pay Attention: RapidJson is header only]
- All source code is written with Pure STL 1z (C++17)
- MSVC 2017, GCC7.x or Clang 7.x
- Add KavenegarLib.dll [on Windows], KavenegarLib.dylib [on macOS] or KavenegarLib.so [on Linux] for your project as external library.
- Import SDK common header ```#include <Kavenegar>```

## Usage Example
```cpp
#include <iostream>
#include <Kavenegar>

int main()
{

  //! Your Api Key
  std::string apiKey {"Your Api-Key"};
  
  //! Kavenegar Default Sender Number 
  std::string senderLine {"10004346"};
  
  //! Http/Https Request method GET/POST type [default is Get method]
  Kavenegar::Method MethodType { Kavenegar::Method::GET }; 
  Kavenegar::KavenegarApi api(MethodType ,"10004346",apiKey);
  
  //ToDo.. try catch exception handling.
  api.send("09140000000","Hi!");
  std::cout << "Result : " << api.getResult(); //JSon Output
    
  return 0;
}

```

## Contribution
Bug fixes, docs, and enhancements welcome! Please let me know kambiz.ceo@gmail.com

## **ToDo**
 * New features
 * Exception handling
 * Post method development
 * Etc...
