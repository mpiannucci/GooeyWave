## THIS PROJECT IS NOT IN DEVELOPMENT, IT WAS JUST A TEST FOR CREATING QT OPEN GL APPS



# GooeyWave

A simple OpenGL wave simulator.

Installing Qt
------------

#### OSX

```bash
brew install qt5 pkfconfig
brew link --force qt5 && ln -s /usr/local/Cellar/qt5/5.4.0/mkspecs /usr/local/mkspecs && ln -s /usr/local/Cellar/qt5/5.4.0/plugins /usr/local/plugins
brew linkapps qt5
```

`Qt` must be added to the user path to expose the correct build specs for some weird homebrew reason.

```bash
export PATH=usr/local/opt/qt5/bin:$PATH
```
