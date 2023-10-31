# IRC: Internet Relay Chat

## IRC quick start

### IRC Clients

To access IRC, we need clients. `hexchat` for gui client, `irssi` for terminal client.

### IRC Servers

IRC chat takes place on IRC servers, such as `irc.freenode.net` or `irc.oftc.net`.

Some server may support registration and login.

In IRC clients, type `/` to enter command mode. (You may be connected to some server by clicking setup wizard if you are using hexchat)
If not, `/connect <server>` to connect to a server.

In a server, such as `irc.freenode.net`, you may now register. 

To register, first choose a nickname by `/nick <nickname>`. Then type `/msg NickServ REGISTER <password> <email>`.

If this this command does not work, try `/msg NickServ HELP REGISTER` to see the help message.

An email will be sent to your email address. Follow the instructions in the email to complete the registration.

After registration, you may login by `/msg NickServ IDENTIFY <password>`. Usually you will be prompted with login instructions.

It shall be noted that most server behave differently. Check server's documentation.

### Helpful Commands

- `/help` to see help message
- `/list` to list all channels
- `/join <channel>` to join a channel 
- `/part <channel>` to leave a channel 
- `/msg <nickname> <message>` to send a private message to a user 
- `/whois <nickname>` to see information about a user
- `/quit` to quit IRC 


## Useful Resources

- [How to Use IRC -- The Basics](https://www.youtube.com/watch?v=ZB8ul4q-H6o)
- [Libera Chat](https://libera.chat/)

