# Tutorial 1

The goal of this tutorial is to give you an understanding of how the network works and how to utilize the network to connect to a cluster.

Lets get a basic understanding of a local area network vs wide area network.

![image](/tutorial1/img/lan_wan.jpg)

For the diagram above it should be clear that the LAN ip ranges and WAN ip ranges will differ. For a PC in LAN 1 to reach a PC in LAN 2, it will have to travel out of its local network and through some external network to reach LAN 2.

Always remember where your cluster is.

## SSH

We will be using ssh to access our cluster. There are many different ssh tools. `Windows CLI` (command line interface) "cmd" , putty or MobaXterm.

![image](/tutorial1/img/moba.jpg)

Highlighted above is all the most  important features we will use.

1. Start a new session
2. Select SSH
3. Enter the end point [remote host] ip
4. Enter the username
5. Locate and select the SSH private key

## SSH key

Your **first task** would be to create a new ssh key for your account. Be very careful with these steps as a mistake can lock you out of your account!

```bash
# Generate new ed25519 key
ssh-keygen -t ed25519 -C "your.email@example.com"

# navigate to ssh key folder
cd ~/.ssh

# Delete the old authorized list
rm authorized_keys

# Create a new empty list
touch authorized_keys

# Add new key to the authorized list of allowed keys
cat id_ed25519.pub >> authorized_keys
```

Make sure to `copy` the `id_ed25519` file to your local machine so that you can start using this as your new ssh key.

## Git

We will now setup and configure git. After git has been setup. Your **second task** is to clone the fork of the repo your captain has created. 

### Configure git

```bash
git config --global user.name "Your Name"
git config --global user.email "your.email@example.com"
```

### Configure SSH for git

```bash
eval "$(ssh-agent -s)"
ssh-add ~/.ssh/id_ed25519
```

### Check if `SSH` is added to git config

```bash
ssh-add -l
```

### Add key to github

Print key

```bash
cat ~/.ssh/id_ed25519.pub
```

On `github` Select repo -> settings -> security -> deploy keys and paste ssh key

### Check SSH connection to Github

```bash
ssh -T git@github.com
```

If this hangs, try a [different port](#try-a-differnt-port) 

### Clone repo

```bash
git clone git@github.com:username/repo.git
```
---
### Try a differnt port

If you could not ssh test github, try a different port

```bash
ssh -T -p 443 git@ssh.github.com
```

If this works then :

```bash
vi ~/.ssh/config
```

Add the following:

```bash
Host github.com
  HostName ssh.github.com
  User git
  Port 443
  IdentityFile ~/.ssh/id_ed25519  
```

Press `esc` then type `:wq` and press enter

---

## Add moderators key

Your **third task** is to add the moderators ssh key to the authorized list of keys.

```bash
# Navigate to the key
cd HPC-Workshop/tutorial1/keys

# Copy the moderators key to the ssh key folder
cp <moderators_key> ~/.ssh/.
```

## Upload created key to repo

Your forth task is to upload/commit your create private ssh key to forked repo.

```bash
# Navigate to the keys folder
cd HPC-Workshop/tutorial1/keys

# Copy ssh key to repo folder
cp ~/.ssh/<private_key> .

# commit and push to repo
```

## Final task

If you struggle with this task you can skip it as it wont stop you from completing the tutorials.

On the cluster machine:

1. create a new folder in tutorial1 folder of the repo
2. 