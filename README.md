# nogil-pybind

The pybind is created by downloading the pybind11 v2.6 branch and replace the
entire `include` folder with the files at https://d1yxz45j0ypngg.cloudfront.net/pybind11/.


```
cmake .
make
python test_pybind.py 100
```
