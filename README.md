# how to run server
```console
foo@bar:~$ make && build/apps/server <PORT>
```
The server will let the system choose a portnumber and display it
for you so that you can start the client application with that port number.

# how to run client
```console
foo@bar:~$ make && build/apps/client <remoteIP> <remotePort>
```

# The following table shows all the REST APIs available for developers
|---------------------|------------------------------------------------|
|   RPC				  |			Description       					   |
|---------------------|------------------------------------------------|
|  Create<User>() |	Creates a new <Resource>  					   |
|---------------------|------------------------------------------------|
|  Get<userID>()    |	Shows information about a specific <Resource>  |
|---------------------|------------------------------------------------|
|  List()   |	Shows a list of all existing <Resources>	   |
|---------------------|------------------------------------------------|
|  Delete<Resource>() |	Deletes an existing <Resource>  			   |
|---------------------|------------------------------------------------|
|  Update<Resource>() |	Updates an existing <Resource> in place  	   |
|---------------------|------------------------------------------------|





| ---------- | ----------- | ------------- | -------------------------------- |
|    URI     | HTTP Method |   POST body   |     Result    			   		  |
| ---------- | ----------- | ------------- | -------------------------------- |
| ---------- | ----------- | ------------- | -------------------------------- |
| login      |    POST     | JSON string   |     login     			   		  |
| ---------- | ----------- | ------------- | -------------------------------- |
| logout     |    POST     | JSON string   |     logs out 			   		  |
| ---------- | ----------- | ------------- | -------------------------------- |
| register   |    POST     | JSON string   | registers new user		   	      |
| ---------- | ----------- | ------------- | -------------------------------- |
| delete     |    POST     | JSON string   | deletes user  			 		  |
| ---------- | ----------- | ------------- | -------------------------------- |
| list       |    GET      | empty         | lists users              		  |
| ---------- | ----------- | ------------- | -------------------------------- |
| reset      |    POST     | JSON string   | resets password			  	  |
| ---------- | ----------- | ------------- | -------------------------------- |
| search     |    POST     | JSON string   | lists users  			  		  |
| ---------- | ----------- | ------------- | -------------------------------- |
| get        |    GET      | JSON string   | get user information  	  		  |
| ---------- | ----------- | ------------- | -------------------------------- |


# Ports used by the REST API

	8080 (HTTP)



# API Status Codes

Example of a response with status code and etc in JSON format.

{
  "success": false,
  "status_code": 5,
  "status_message": "Login fail, wrong password"
}

| ---------- | ----------- | --------------------------------------------------------------------------- |
|    Code    | HTTP Status |   Message     								 								 |
| ---------- | ----------- | --------------------------------------------------------------------------- |
|    1       | 200         |   Success     								 								 |
| ---------- | ----------- | --------------------------------------------------------------------------- |
|    2       | 201         |  The request has been fulfilled, resulting in the creation of a new resource |
| ---------- | ----------- | --------------------------------------------------------------------------- |
|    3       | 400         |  Could not interpret the request      										 |
| ---------- | ----------- | --------------------------------------------------------------------------- |
|    4       | 401         |  Incorrect username 			 								 |
| ---------- | ----------- | --------------------------------------------------------------------------- |
|    5       | 401         |  Incorrect password      		 								 |
| ---------- | ----------- | --------------------------------------------------------------------------- |
|    6       | 403         |  Request denied, client not logged in     		 		  					 |
| ---------- | ----------- | --------------------------------------------------------------------------- |
|    7       | 409         |  Registration declined, username already exists   		  					 |
| ---------- | ----------- | --------------------------------------------------------------------------- |
|    8       | 404         |  User not found								   		  					 |
| ---------- | ----------- | --------------------------------------------------------------------------- |
|    9       | 403         |  Wrong password    
| ---------- | ----------- | --------------------------------------------------------------------------- |
|    10       | 401         |  Access token needed for operation 
| ---------- | ----------- | --------------------------------------------------------------------------- |
|    11       | 401         |  Invalid access token
| ---------- | ----------- | --------------------------------------------------------------------------- |



| -------------- | --------------------------- | --------------------------------------------------------------------------- |
|    Command     | Arguments   				   | Why ?         						 									 |
| -------------- | --------------------------- | --------------------------------------------------------------------------- |
|    help        | 			   				   | You need help								 								 |
| -------------- | --------------------------- | --------------------------------------------------------------------------- |
|    search      | 	username/name/email		   | search for a user							 								 |
| -------------- | --------------------------- | --------------------------------------------------------------------------- |
|    reset       | 							   | set new password from email				 								 |
| -------------- | --------------------------- | --------------------------------------------------------------------------- |
|    exit        | 							   | exits application							 								 |
| -------------- | --------------------------- | --------------------------------------------------------------------------- |