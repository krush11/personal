# Nginx Reverse Proxy
Nginx, is a web server that can also be used as a reverse proxy, load balancer, mail proxy and HTTP cache.

This tutorial will explain how to deploy a nginx server at URI http://${IP_ADDRESS} (defaulted at port 80).

## Pre-requisites
1. Nodejs server (developed prior)
2. `pm2` (npm package) installed globally.
```bash
npm i -g pm2
```
3. nginx
```bash
sudo apt install nginx
```

## Brief explaination
1. Nginx reverse proxy configures a given port(default 80) of a machine to give the output of a service running on a different port and/or URL.
2. nginx configuration folder is available on `/etc/nginx`
3. `/etc/nginx/sites-available` can be used to add the nodejs server.
4. pm2 is used to run a node server continuously in the background so that you can use terminal for some other use.

## Pre-setup
1. Develop a nodejs server
2. Take a note of which server the app is running on. For this turtorial we will assume that the app runs on port 3000.

## Setup
1. Enter the node server directory.
2. Start the node server using pm2.
```bash
pm2 start app.js    # Considering the server file name to be app.js
```
3. Check is server is running on pm2
```bash
pm2 list
```
4. Go to the nginx folder available at `/etc/nginx`.
5. Open the file `sites-available/default`. (Prefferably use root access to edit)
6. Edit the location part of the server as this:
```bash
location / {
    proxy_pass http://localhost:3000;       # Edit this to point to the URL and port of the node server
    proxy_http_version 1.1;
    proxy_set_header Upgrade $http_upgrade;
    proxy_set_header Connection 'upgrade';
    proxy_set_header Host $host;
    proxy_cache_bypass $http_upgrade;
}
```
> Note: There will be line such as the one given below which can be used to provide port on which reverse proxy is to be outputted. Here the output port will be 80
```
listen 80 default_server;
listen [::]:80 default_server;
```
7. Restart nginx
```bash
sudo systemctl restart nginx
```

The output will now be visible on the IP address of the machine. eg. http://bc.def.ghi.jk