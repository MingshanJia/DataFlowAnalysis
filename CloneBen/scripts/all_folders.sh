# this is to process sub directories /0 to /5

script="one_folder.sh"

for folder in */
do
  echo $folder
  $CLONESCRIPTS/$script $folder
done

echo finished!
