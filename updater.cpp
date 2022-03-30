#include<iostream>
#include<fstream>
using namespace std;
void init()
{
	system("rm -rf /tmp/chroot-box86-wine/");
	system("mkdir /tmp/chroot-box86-wine/");
}
int arch()
{
	system("arch > /tmp/chroot-box86-wine/arch.txt");
	ifstream arch ("/tmp/chroot-box86-wine/arch.txt");
	char architecture[4];
	for(int i=1;i<=3;i++)
	{
		arch>>architecture[i];
	}
	if(architecture[1]=='a'&&architecture[2]=='a'&&architecture[3]=='r') 
	{
		cout<<"arm64";
		return 1;
	}
	else if(architecture[1]=='a'&&architecture[2]=='r'&&architecture[3]=='m')
	{                                                        
	       	cout<<"armhf";
		return 1;
        }
	else
	{
		return 0;
	}


	
}
void installaria2()
{
	system("apt install aria2 -y 2>/dev/null 1>/dev/null");
}
void installgit()
{
	system("apt install git -y 2>/dev/null 1>/dev/null");
}

void downloadlatestrelease()
{
//	system("cd /tmp/chroot-box86-wine&&aria2c https://github.com/VMware16/chroot-box86-wine-updater/releases/download/latest-lts-version-release/chroot-box86-wine-latest.deb -x 16");
	system("cd /tmp/chroot-box86-wine/&&git clone http://gitee.com/vmware16/chroot-box86-wine__cache__. 1>/dev/null 2>/dev/null");
	system("chmod +x  /tmp/chroot-box86-wine/chroot-box86-wine__cache__./download_script/chroot-box86-wine-downloader.sh");
	system("bash  /tmp/chroot-box86-wine/chroot-box86-wine__cache__./download_script/chroot-box86-wine-downloader.sh");

	
}
void installlatestchrootbox86wine()
{
	system("apt reinstall /tmp/chroot-box86-wine/chroot-box86-wine-container-image.deb -y 2>/dev/null 1>/dev/null");
}
void databackup()
{
	system("mv /opt/VMware16/containers/chroot/winehq7.2:i386/debian11armhf/root/ /tmp/chroot-box86-wine/root");
}
void datarecover()
{
	system("rm -rf /opt/VMware16/containers/chroot/winehq7.2:i386/debian11armhf/root");
	system("mv /tmp/chroot-box86-wine/root /opt/VMware16/containers/chroot/winehq7.2:i386/debian11armhf/");
}
void remove()
{
	system("rm -rf /opt/VMware16/containers/chroot/winehq7.2:i386/debian11armhf/*");
}

int main()
{
/*	init();
	aria2();
	bool architecture=arch();
	if(architecture==1)
	{
		download();

	
	}
*/
	init();
	installaria2();
	installgit();
	cout<<"cpu架构为";
	bool b=arch();
	cout<<endl;

	if(b)
	{
		downloadlatestrelease();
		databackup();
		remove();
		installlatestchrootbox86wine();
		datarecover();

	
	}

}
