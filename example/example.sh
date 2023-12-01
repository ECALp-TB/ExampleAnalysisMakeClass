echo "I run the example for file ../../../TB2022/data/calice-c75.root and only the first 10 entries"
root -l -q Example.cc\(\"../../../TB2022/data/calice-c75.root\",10\)

echo "I do the same but for 20"
root -l -q Example.cc\(\"../../../TB2022/data/calice-c75.root\",20\)