#!/bin/bash  
git add . && \
git add -u && \
read -p "Commit description: " desc  
git commit -m '$desc'  
curl -u '[adithyabhat99]:[Ma*123654654]' https://api.github.com/user/
git push origin master