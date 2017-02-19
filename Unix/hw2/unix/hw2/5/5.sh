
echo "*/1 * * * */bin/bash `readlink -f tmp_file`" | crontab -
