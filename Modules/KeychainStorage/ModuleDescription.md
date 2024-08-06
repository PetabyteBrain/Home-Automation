
<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/PetabyteBrain/Home-Automation">
    <img src="images/logo.png" alt="Logo" width="80" height="80">
  </a>

<h3 align="center">Home Automation System</h3>
<h4 align="center">Module: Keychain Storage Button</h4>

  <p align="center">
    A Home Automation System built with Esp32 boards.
    <br />
    <a href="https://github.com/PetabyteBrain/Home-Automation"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/PetabyteBrain/Home-Automation">View Demo</a>
    ·
    <a href="https://github.com/PetabyteBrain/Home-Automation/issues/new?labels=bug&template=bug-report---.md">Report Bug</a>
    ·
    <a href="https://github.com/PetabyteBrain/Home-Automation/issues/new?labels=enhancement&template=feature-request---.md">Request Feature</a>
  </p>
</div>

<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-Module">About The Module</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#works-with">works with</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>

## About The Module

[![Product Name Screen Shot][product-screenshot]](https://example.com)

This Module has 2 parts to it, the first part is a 3d printed dish triggered by a button press when an object is placed. The button press then calls out to the second part which is another Esp32 programmed to turn on an extension cord which can turn on other devices (for example: Lights turning on when entering a room and putting down your keys at the entrance).

<p align="right">(<a href="#readme-top">back to top</a>)</p>



### Built With

* [![Cplusplus][CPP.cpp]][CPP-url]
<!-- 
* [![React][React.js]][React-url]
* [![Vue][Vue.js]][Vue-url]
* [![Angular][Angular.io]][Angular-url]
* [![Svelte][Svelte.dev]][Svelte-url]
* [![Laravel][Laravel.com]][Laravel-url]
* [![Bootstrap][Bootstrap.com]][Bootstrap-url]
* [![JQuery][JQuery.com]][JQuery-url]
 -->
<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- GETTING STARTED -->
## Getting Started

I decided to create this module as a way to make my daily life easier. This Module can be used daily as most people put down their things when coming home from work / school / other places. Due to this fact this module can easily be adapted for different objects by changing the size of it to acount for different objects like Keys, wallets, phones and others.

After coming home you can save time by having this Module to automate different processes (for example: Turning on Lights at home, opening the blinds ...). 

### Prerequisites

you need these things to be able to build this Module:

#### Hardware:
1. Two or more Esp32 boards (atleast 2 for the button trigger and for the Extension cord one, if needed more can be used but the code needs to be adjusted for the amount)
2. Breadboard
3. Jumpercables for Breadboard
4. LEDs to show status (green, Blue, Red)
5. 3D printer / housing for the module(to Print the case for the Module) ***optional***

#### Software:
1. Arduino IDE (to programm the microcontrollers)

After having checked these prerequisites you should be ready to build this Module.

### works with
Depending on the Usecase and the Setup used there are countless possibilities for Modules to be created and adapted, for that reason I made a List with multiple example Modules that can be used as is or adapted for individual use.

1. Keychain Button trigger.
2. Stepper Motor Extension cord activator
3. ... (more coming soon)

### Installation

The Installation works by ...

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- USAGE EXAMPLES -->
## Usage

This Project can be applicable in multiple different usecases and as such cannot just get copied across and used in the same way for everyone.

Here are a couple of Examples of how these Modules can be put to use:

### 1. Key Input to first Automation.
In this Example the Esp32 waits for the Button press that occurs when the House keys or another object is placed on the surface. The Result of this action is that the first Automation is trigered.
...
...

_For more examples, please refer to the different [Modules](https://github.com/PetabyteBrain/Home-Automation/tree/main/Modules)_

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- ROADMAP -->
## Roadmap

- [x] Get Idea for Module
- [x] plan construction and functioning
- [x] split module into seperate parts (buton trigger & motor activator)
- [x] research how to make multiple esp32 comumnicate and how Esp-now works
  - [x] start building module on breadboard
  - [ ] programm module.
- [ ] Design Housing for the seperate parts of the module
  - [ ] 3d print and test out module with housing
  - [ ] make changes if need be
- [ ] document module and it's function

See the [open issues](https://github.com/PetabyteBrain/Home-Automation/issues) for a full list of proposed features (and known issues).

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- LICENSE -->
## License
This Readme file is under the MIT License and the Rest of the Project is under the GNU General Public License. See `LICENSE.txt` for more information.

### MIT License 
```
MIT License

Copyright (c) 2021 Othneil Drew

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
```

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTACT -->
## Contact

Spyros Catéchis - catechisspyros@gmail.com

Project Link: [https://github.com/PetabyteBrain/Home-Automation](https://github.com/PetabyteBrain/Home-Automation)

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

* []()
* []()
* []()

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/PetabyteBrain/Home-Automation.svg?style=for-the-badge
[contributors-url]: https://github.com/PetabyteBrain/Home-Automation/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/PetabyteBrain/Home-Automation.svg?style=for-the-badge
[forks-url]: https://github.com/PetabyteBrain/Home-Automation/network/members
[stars-shield]: https://img.shields.io/github/stars/PetabyteBrain/Home-Automation.svg?style=for-the-badge
[stars-url]: https://github.com/PetabyteBrain/Home-Automation/stargazers
[issues-shield]: https://img.shields.io/github/issues/PetabyteBrain/Home-Automation.svg?style=for-the-badge
[issues-url]: https://github.com/PetabyteBrain/Home-Automation/issues
[license-shield]: https://img.shields.io/github/license/PetabyteBrain/Home-Automation.svg?style=for-the-badge
[license-url]: https://github.com/PetabyteBrain/Home-Automation/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/spyros-catechis-0117242a6
[product-screenshot]: images/screenshot.png
[CPP.cpp]: https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white
[CPP-url]: https://www.arduino.cc/
[React.js]: https://img.shields.io/badge/React-20232A?style=for-the-badge&logo=react&logoColor=61DAFB
[React-url]: https://reactjs.org/
[Vue.js]: https://img.shields.io/badge/Vue.js-35495E?style=for-the-badge&logo=vuedotjs&logoColor=4FC08D
[Vue-url]: https://vuejs.org/
[Angular.io]: https://img.shields.io/badge/Angular-DD0031?style=for-the-badge&logo=angular&logoColor=white
[Angular-url]: https://angular.io/
[Svelte.dev]: https://img.shields.io/badge/Svelte-4A4A55?style=for-the-badge&logo=svelte&logoColor=FF3E00
[Svelte-url]: https://svelte.dev/
[Laravel.com]: https://img.shields.io/badge/Laravel-FF2D20?style=for-the-badge&logo=laravel&logoColor=white
[Laravel-url]: https://laravel.com
[Bootstrap.com]: https://img.shields.io/badge/Bootstrap-563D7C?style=for-the-badge&logo=bootstrap&logoColor=white
[Bootstrap-url]: https://getbootstrap.com
[JQuery.com]: https://img.shields.io/badge/jQuery-0769AD?style=for-the-badge&logo=jquery&logoColor=white
[JQuery-url]: https://jquery.com 
