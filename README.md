# comprog-library

### Usage
For local testing:
```
g++ solution.cpp -o solution -std=gnu++17 -I path-to-here/comprog-library
```

For use in compets:
Use `expander.py` to merge the contents of this library to your code:
```
python3 expander.py path-to-solution/solution.cpp --res path-to-solution/solution_merged.cpp
```
And then compile as usual (or submit to judge):
```
g++ solution_merged.cpp -o solution -std=gnu++17
```
