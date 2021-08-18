# Azure Cloud Storage
Azure containers allow storing files for using cloud service. `@azure/storage-blob` is tailored specifically as an npm package for that.
This tutorial will guide through the process of using `@azure/storage-blob` to upload files from a ReactJS code to Azure.

Blobs are any type of files which can be stored 
## Pre-requisites
1. Azure account
2. npm

## Pre-Setup
1. Login to your Azure account.
2. Go to Storage accounts and create a new Storage account
3. Open the storage account and go to 'SAS Tokens' under Settings section.
4. Generate a token by giving necessary access. Cope the SAS token(will be used later).
5. Go to 'CORS Resources' under Settings section.
6. Add your device to list. If access is to be given to any and all users, set all fields as '*' and save.

## Setup
1. Install `@azure/storage-blob`
```bash
npm install @azure/storage-blob
```
2. Inside the storage account create a container.
3. Add a .env file and add the following details.
```txt
REACT_APP_AZURE_STORAGE_ACCOUNT=paste_storage_acc_name
REACT_APP_AZURE_SAS_TOKEN=paste_sas_token_here
```
4. Add this code to the function where file is given (you could use multer, to get files from html):
> There are many methods to upload different types of blob but azure has deprecated all those methods and replaced all with `uploadData()`. This method will call the necessary method by itself based on the type of data in arguments.
```js
import { BlobServiceClient } from '@azure/storage-blob';

// REACT_APP_AZURE_STORAGE_ACCOUNT is the name of the storage account in which the container is listed
// REACT_APP_AZURE_SAS_TOKEN is the SAS token you got from the pre-setup.
const blobService = new BlobServiceClient(`https://${process.env.REACT_APP_AZURE_STORAGE_ACCOUNT}.blob.core.windows.net/${process.env.REACT_APP_AZURE_SAS_TOKEN}`);
const containerName = '';           // Add container name to the empy string
const containerClient = blobService.getContainerClient(containerName);
const blockBlobClient = containerClient.getBlockBlobClient(`recording${Date.now()}.mp4`);
const uploadResult = await blockBlobClient.uploadData(blob);
if (uploadResult._response.status !== 201)
    console.log(typeof uploadResult._response.status);
});
var cadUrl = blobService.getUrl(containerName, fileName);
```

This will add your file to the container as a blob.  

**[Source Code](https://github.com/Azure/azure-sdk-for-js/tree/master/sdk/storage/storage-blob) | [Package (npm)](https://www.npmjs.com/package/@azure/storage-blob/) |  [API Reference Documentation](https://docs.microsoft.com/javascript/api/@azure/storage-blob) | [Product documentation](https://docs.microsoft.com/azure/storage/blobs/storage-blobs-overview) | [Samples](https://github.com/Azure/azure-sdk-for-js/tree/main/sdk/storage/storage-blob/samples)**