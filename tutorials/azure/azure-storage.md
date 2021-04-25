# Azure Cloud Storage
Azure containers allow storing files for using cloud service. `azure-storage` is tailored specifically as an npm package for that.
This tutorial will guide through the process of using `azure-storage` to upload files from backend `NodeJs` code to Azure.

Blobs are any type of files which can be stored 

## Pre-requisites
1. Azure account
2. npm

## Pre-Setup
1. Login to your Azure account.
2. Go to Storage accounts and create a new Storage account
3. Open the storage account and go to 'Access Keys' under Settings section.
4. Copy the connection string separately (you will need this soon).

## Setup
1. Install `azure-storage`
```bash
npm install azure-storage
```
2. Inside the storage account create a container.
3. Add this code to the function where file is given (you could use multer, to get files from html):
```js
const azure = require('azure');

const AZURE_STORAGE_CONNECTION_STRING = "connection-string";    // Connection string you got from the pre-setup step
var blobService = azure.createBlobService();                    // initiate service
var containerName = "container-name";                           // The name of container you created in the storage account
var fileName = "filename";                                      // Name you want the file to be stored with in container
var filePath = "path-relative-to-current-directory";            // Path to the file
blobService.createBlockBlobFromLocalFile(containerName, fileName, filePath, function (err, result, response) {
    // callback function 
});
var cadUrl = blobService.getUrl(containerName, fileName);
```

#### This will add your file to the container as a blob.  
#### For more documentation check out the [package source](https://www.npmjs.com/package/azure-storage).  
#### Feel free to contact me for any more queries of post an issue [here](https://github.com/krush11/ask-anything-forum).
