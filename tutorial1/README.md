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

Your first task would be to create a new ssh key for your account. Be very careful with these steps as a mistake can lock you out of your account!

```bash
# Generate new ed25519 key
ssh-keygen -t ed25519

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

