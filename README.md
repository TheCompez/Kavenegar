## Kavenegar SDK
Kavenegar SDK for modern C++17

## Version 0.6 (Alpha-Concept)

# <a href="http://kavenegar.com/rest.html">Kavenegar RESTful API Document</a>
If you need to future information about API document Please visit RESTful Document

## Installation
<p>
First of all, You need to make an account on Kavenegar from <a href="https://panel.kavenegar.com/Client/Membership/Register">Here</a>
</p>
<p>
After that you just need to pick API-KEY up from <a href="http://panel.kavenegar.com/Client/setting/index">My Account</a> section.
 
## Building

- You need to CMake tool for build source code
- Get Curl & RapidJson
- All source code is written with Pure STL 1z (C++17)
- MSVC 2017, GCC7.x or Glang 7.x

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
  
  //! Http/Https Request method type
  Kavenegar::Method MethodType { Kavenegar::Method::GET };
  Kavenegar::KavenegarApi api(MethodType ,"10004346",apiKey);
  
  //ToDo.. try catch exception handling.
  api.send("09140000000","Hi!");
  std::cout << "Result : " << api.getResult(); //JSon Output
    
  return 0;
}

```

## **ToDo**
 * New features
 * Exception handling
 * Post method development
 * Etc...
