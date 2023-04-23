make
for file in ../tests/*; do 
    ./a.out $file
    x=$(echo "${file##*_}")
    x=${x%.*}
    mv Assembly.s Assembly_$x.s
done