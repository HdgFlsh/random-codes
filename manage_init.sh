#!/bin/sh
mkdir ~/.ssh
cp --parents ../.ssh/id_rsa* ~/.ssh
git config --global user.name "Kevin Zhou"
git config --global user.email "10206651-hdgflsh@users.noreply.gitlab.com"
#git pull
echo "alias ls='ls --color'" >> ~/.bashrc
source ~/.bashrc
du ./src ./doc ./archive -hs
