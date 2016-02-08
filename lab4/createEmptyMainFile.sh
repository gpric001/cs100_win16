#!/bin/sh

echo "/*" > main.cpp
cat Guthrie_861238612.txt >> main.cpp 
echo -e "*/\nint main(int argc, const char** argv)\n    {}" >> main.cpp
