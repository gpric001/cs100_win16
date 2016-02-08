#!/bin/sh

header=${1}.h
class=${1}.cpp
echo "/*" > temp
cat Guthrie_861238612.txt >> temp
echo -e "*/\n" >> temp
cat temp > $header
echo -e "#ifndef ${1}_h\n#define ${1}_h\n\nclass ${1}{
    public:\n        ${1}();\n        ~${1}();\n    private:\n};\n#endif" >> $header
cat temp > $class
echo -e "#include \"./${1}.h\"\n\n${1}::${1}()\n{}\n\n${1}::~${1}()\n{}" >> $class
rm temp
