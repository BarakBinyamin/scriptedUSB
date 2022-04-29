curl -s https://barakbinyamin.github.io/scriptedUSB/img/forHeather.txt

curl https://someresources.github.io/songs/boss.m4a -o boss.m4a
open boss.m4a --hide

#set general volume
osascript -e "set volume 3"

for i in {1..15}; do
	volume=`echo "$(( i / 10)).$(( i % 10))"`

	#set itunes volume
	osascript -e "tell application \"Music\" to set sound volume to $volume"
	sleep .25
done
