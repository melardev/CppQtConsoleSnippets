# Introduction
This repository contains Qt C++ snippets NOT related to UI, for UI snippets I have another repository<br>.
I have a lot more snippets, but they have to be refactored before pushing them to Github.<br>
Stay tuned, a lot more will come.

At this moment I publish only the snippets, the project setup will come later, I will give instructions
on how to set this up with the awesome vcpkg and Visual Studio and CMake.

# Tips
- In C++ development many errors are fixed after Cleaning the project/Solution, in Qt this occurs even more
than in other frameworks in my opinion, that is due to the moc system and all the intermediate steps before
generating the executable. So If an error is not obvious try cleaning the project and re-compile.
<br>
- When you have a non obvious error, such as, there is no definition for X, when you know there is<br>
try #include(ing) the class because Qt uses a lot of class forwarding so, as soon as you import a single
class, your IDE will recognize a lot of other classes used in your file, so you may think its ok,<br>
you won't need to import all other Qt classes you are using, this is sometimes true, but sometimes it is not.
<br>
- Try learning Qt internals debugging into Qt source code from time to time, because not everything is on the docs,
but everything is in the code.

# Social Media
- [Youtube](https://youtube.com/Melardev)
- [Twitter](https://twitter.com/@melardev)
- [Instagram](https://instagram.com/melar_dev)

# Resources

# TODO
- Port to CMake