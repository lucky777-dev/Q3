# DEV3-cpp Romain Absil (abs)
## Build

### Make from within a chapter directory
#### Build while editing
To build and preview the slides with an automatically triggered rebuild of the slides when one of the dependant files changes:
```
make preview
```

#### Build directly
Make the handouts and the slides:
```
make
```

Make the slides:
```
make slides.pdf
```

Make the handouts:
```
make slides-handout.pdf
```

### Make from top-level directory

#### Build a chapter
Make chapter 4, [everything/handouts/slides/clean]:
```
make [ch4|ch4-handout|ch4-slides|ch4-clean]
```

#### Build everything

Make all the handouts using 4 build processes:
```
make -j4 [handouts|slides]
```

Make *everything*, slides and handout:
```
make -j4
```

#### Clean everything
```
make clean
```
