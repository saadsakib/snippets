# Example 1: Save a value in an array and retrieve it
a[1]=foo
echo ${a[1]}



# Example 2: Different types of traversal
# last one better?
animals=("a dog" "a cat" "a fish")
for i in ${animals[*]}; do echo $i; done
echo ""
echo ""
for i in ${animals[@]}; do echo $i; done
echo ""
echo ""
for i in "${animals[*]}"; do echo $i; done
echo ""
echo ""
for i in "${animals[@]}"; do echo $i; done


# Example 3: Check if a value is in array or not
# Taken from: https://stackoverflow.com/questions/3685970/check-if-a-bash-array-contains-a-value

# Multiple values are assigned within parentheses 
days=(Sun Mon Tue Wed Thu Fri Sat)

today="Tue"
tomorrow="Wedd"
if [[ " ${days[@]} " =~ " ${today} " ]]; then
    # whatever you want to do when array contains value
    printf "contains %s\n" ${today}
fi

if [[ ! " ${days[@]} " =~ " ${tomorrow} " ]]; then
    # whatever you want to do when array doesn't contain value
    printf "doesn't contain %s\n" ${tomorrow}
fi