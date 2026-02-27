*This project has been created as part of the 42 curriculum by bgorski.*

# Born2BeRoot

## Description

Born2BeRoot aims to introduce to the world of virtualization. 

During this project I could:
- remind Virtualization fundamentals with VirtualBox

- perform my first Debian installation and partition configuration (LVM)

- ensure the security of the system by:
  - setting firewall (UFW) and sudo policies
  - User and group management
  - setting password secure password policy

- create monitoring script and schedule job with cron

---

## Why Debian?

- Large package repositories  
- Strong community support  
- Excellent documentation
- Reccomended by other peers
---

## Debian vs Rocky Linux

| Debian 		       | Rocky Linux 						  |
|----------------------|--------------------------------------|
| APT 			       | DNF/YUM   	   						  |
| Faster updates 	   | Very conservative updates			  |
| Easier for beginners | Designed for production environments |

**Decision:** Debian was chosen mainly because of its similarity to Ubuntu, but also because of its simplicity and large user community. 

---

## AppArmor vs SELinux

| AppArmor | SELinux |
|-------------------------|-------------------------------|
| Profile-based security  | Label-based security 		  |
| Default in Debian 	  | Default in Rocky 			  |
| Better at the beginning | Better for more advanced users|

**Decision:** AppArmor was selected because it integrates naturally with Debian.

---

## UFW vs firewalld

| UFW 				| Firewalld 			   |
|-------------------|--------------------------|
| Beginner-friendly | More advanced 		   |
| Simple CLI 		| Zone-based configuration |

**Decision:** UFW was chosen for its simplicity and fast setup while still offering sufficient security.

---

## VirtualBox vs UTM

| VirtualBox              | UTM 				|
|-------------------------|---------------------|
| Cross-platform          | Optimized for macOS |
| Mature ecosystem 		  | Newer               |
| Extensive documentation | Smaller community   |

**Decision:** VirtualBox was selected due to stability, availability, and strong documentation.

---

## Instruction

### Instalation and partitioning
The disk was partitioned using LVM with encryption.

### Security Policies
- SSH configured on port **4242**
- Root login disabled
- Strong password rules enforced
- Firewall enabled with only required ports open
- Sudo logs stored for auditing
- TTY mode enabled

### User Management
- Created a non-root user with sudo privileges  
- Added user to required groups  
- Implemented password expiration and complexity rules  

### Services Installed
- OpenSSH  
- UFW  
- AppArmor  
- cron  

---

### Requirements
- VirtualBox installed
- Debian ISO

### Creating a new virtual machine.

	1. Run VirtualBox.
	2. Set name and attach Debian ISO
	3. Uncheck **Proceed with Unattended Installation**
	4. Allocate resources (6GB RAM, 4CPUs, 20GB of Disk Size)
	5. Finish configuration
	6. Run virtual machine

---

### During Debian installation and configuring LVM partition follow instructions from Debian Administrator's Handbook (link below)
---

### SUDO

To check sudo version write:
```bash
sudo -V
```


---

### Adding users and groups

To add new user write:

```bash
sudo adduser <user>
```

You can also add new group to manage users' permission simpler:
```bash
sudo groupadd <group>
```

Then you can add new user to the group:
```bash
sudo adduser <user> <group>
```

To check if opereation was completed succesfully:
```bash
getent group <group>
```

---

### SSH

To check ssh status write
```bash
sudo service ssh status
```
#### Setting 4242 port and root login prohibition for SSH service

I modified two lines in **/etc/ssh/sshd_config** file:
  - Port 4242
  - PermitRootLogin no

#### Setting connection
To connect with your VM you need to set port forwarding firstly.
1. Open VirtualBox Network settings.
2. Add new network NAT adapter:
		 **Protocol**: TCP, 
		 **Host IP**: Empty, 
		 **Host Port**: 4242, 
		 **Guest Port**: 4242
		 **Guest IP**: IP address of you virtual machine. How to get it?
		 Write in VM:
  			```bash
			hostname -I | awk '{print $1}'
			 ```. It'll return IP address, 
3. On hosting terminal (NOT VM) write: ```bash ssh <user>@localhost -p 4242 ```. You could see information that ``` REMOTE HOST IDENTIFICATION HAS CHANGED```. If it's happen:
   Delete on you PC ECDSA key from ~/.ssh/known_hosts file. It should begin with ```[localhost]:4242```. Then, try to connect again.
---

### Firewall (UFW)

To check UFW status write:
```bash
sudo ufw status
```
---

### Password policy

#### Sudo policy configuration.
here was cofigured sudo password policy. To check policy rules you can look at */etc/sudoers.d/sudo_config* file:
```bash
cat /etc/sudoers.d/sudo_config
```
#### Applying password rules
Firstly I modified time how long is set password active. To complete this part I modified two lines in **/etc/login_defs**:
```bash
PASS_MAX_DAYS 30
PASS_MIN_DAYS 2
```

#### Bash script

At the location **~/.** there is a bash script called monitoring.sh. It display some information:

	- The architecture of your operating system and its kernel version.
	- The number of physical processors.
	- The number of virtual processors.
	- The current available RAM on your server and its utilization rate as a percentage.
	- The current available storage on your server and its utilization rate as a percentage.
	- The current utilization rate of your processors as a percentage.
	- The date and time of the last reboot.•Whether LVM is active or not.
	- The number of active connections.•The number of users using the server.
	- The IPv4 address of your server and its MAC (Media Access Control) address.
	- The number of commands executed with the sudo program
Bash script is run on all terminals and every 10 minutes. To handle running script every 10 minutes there was used ```cron```. It is a background service that automatically runs scheduled commands or scripts.

## Resources

- Instalation Process - Debian Administrator’s Handbook 

https://debian-handbook.info/browse/stable/sect.installation-steps.html

- Markdown Table Generator

https://www.tablesgenerator.com

- Debian User Manual

https://wiki.debian.org/DebianUserManual

- Setting password rules

https://www.server-world.info/en/note?os=Debian_10&p=password




