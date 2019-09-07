Drawing App
======

![Screenshot](https://lh5.googleusercontent.com/-y40TrMwn3Ac/VWMzffXUf5I/AAAAAAAACLg/1WEoJZxaNSI/w659-h445-no/2015-05-25%2B22_35_03-.png)

[ [Link to video demonstration](https://www.youtube.com/watch?v=_Mo0yeKc6xk) ]

This Drawing App has no functional purpose by itself; it is an experiment of complexity management to test how much requirements (and maybe future requirements) I can mash together by designing software properly. I'm not quite sure if I was successful, but at the time it was the most complex piece of work I've created.

Technically this app will compile in any OS that Qt 5 supports, given you have a C++11 compliant compiler. I heavily rely on lambdas, foreach loops, auto, some smart pointers and other C++11 goodness. Below is the original UML class diagram I drew up in WhiteStarUML before implementation:

![UML Class Diagram](https://lh5.googleusercontent.com/-o_ayphJwvHM/VWOAvd6SlkI/AAAAAAAACMo/Eq-EJgTW35I/w973-h518-no/Main.jpg)

This app has been tested in Windows 8.1 (MSVC++2013) and Manjaro Linux (MinGW 4.8).

### Dependencies
Used as of this writing
- Qt Creator 3.3.0
- Qt 5.4
- C++11 compliant compiler
- Catch Unit Test Framework (bundled)

### Credits
Icons are from various sources mashed up together:
- https://github.com/FortAwesome/Font-Awesome/issues/1445
- http://findicons.com/pack/2226/matte_basic
- Qt SDI example

### License
I don't care what you do with it. However, if you find this useful, do drop me a love letter and say thanks (:
