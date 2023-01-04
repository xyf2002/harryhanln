# Note for Using Git

## Authentication with github.

Git credential manager (integraged with Git's built in credential cache) is used for authentication on this device to github.

The authentication was set up by first installing git credential-manager; and secondly use the code 
`git config --global credential.credentialStore cache "--timeout 3000"`. 

`--timeout 3000` sets the automatic expiration of this aunthentication in 3000 seconds.

Authentication is, as expected for any functionalities related to security, extremely complicated, and information of which can be found on github website. 

## Basics APIs

### Connecting to Remote

#### Adding Remote Depository

The command `git clone <URL_to_depository>` will add the remote despository automatically (with the shortname `origin`). 

Use the following code the add manually a remote with the shortname `<shortname>`.

`git remote add <shortname> <URL_to_depository>`

The command `git clone <URL_to_epository>` will add the remote despository automatically (usually with the shortname `origin`). 

Now the `<shortname>` can be used in lieu of the whole URL. 

`git fetch <remote>` will download all data from the remote depository, including references to remote branched. However, it does not merge, pull, or modify existing branch. 

#### Inspecting, Renaming. and Removing Remotes

`git remote show origin` 
`git remote rename <oldname> <newname>`
`git remote remove <remotename>`
`git branch -vv` (This will show the local branched and their remote counterparts.)
#### Pushing to Remote

It is most easy and straighforward to have the same number of branches all with the same names in the remote and local depositories. 

Starting from cloning only the main branch from the remote to the local, here is the work flow to set up the `dev` branch on local, pushes and merges to `dev` branch in the remote.

1. On remote, create a new branch named `dev`;
2. At the local position, download the branch reference by 
`git fetch origin`
3. Create the local branch dev on local and checkout this bracnh by
`git checkout -b dev`;
4. Set the upstream of local branch `dev` to be the remote branch `dev` by the command:
`git branch -u origin/dev`



