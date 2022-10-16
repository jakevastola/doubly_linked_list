# Doubly Linked List
> A type of linked list that can be traversed forwards and backwards.

This repository is a brief demonstration of my knowledge of the Git version control system and GitHub functionality.

This repository is an example of how I was able to:
* Stage and commit changes
* Create a pull request
* Create and merge a branch

## Downloading
#### Method 1: Manual Download
1. Click the green button `Code` to reveal a dropdown menu.
2. Click `Download ZIP` to download a ZIP file to your local machine.
3. Navigate to the `Downloads` directory on your local machine.
4. Extract the ZIP file with the use of a file archiver (such as [7-Zip](https://www.7-zip.org/download.html)).

#### Method 2: Clone the repository
Note: By default, unless you specify your directory, the directory of the cloned repository will be `/home/YOUR_USERNAME`.
```sh
git clone https://github.com/jakevastola/doubly_linked_list.git
```


## Running the program
```sh
gcc doubly_linked_list.c -o doubly_linked_list.out

./doubly_linked_list.out
```

## Sample Output
```sh
[26] - [6] - [70] - [40] - [89]

After inserting 10 into the front: 
[10] - [26] - [6] - [70] - [40] - [89]

After inserting 20 into the end: 
[10] - [26] - [6] - [70] - [40] - [89] - [20]

Enter the node you want to delete: 40

Just deleted 40: 
[10] - [26] - [6] - [70] - [89] - [20]
```


## License
This repository is licensed under the MIT License.
