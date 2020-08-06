# Example 1: Display a series of numbers.
count=1

while [ $count -le 5 ]; do
    echo $count
    count=$((count + 1))
done

echo "Finished."


# Example 2: Read lines from a file.
a_file="students.txt"
touch $a_file 
echo "a 27" > $a_file
echo "b 56" >> $a_file

while read name roll; do
    printf "Name: %s, Roll: %s\n" \
    $name \
    $roll 
done < $a_file