class Item
{
	public:
		Item(int inprice=0,int outprice=0);
		int getnum{return num;}
		void get{num++;}	//�����Ʒ 
		void lose{num--;}	//ʧȥ��Ʒ 
	private:
		int inprice;		//��Ʒ����۸� 
		int outprice;		//��Ʒ���ۼ۸� 
		int num=0;			//��Ʒӵ������ 
}
class Drug:public Item		//ҩƷ 
{
	public:
		Drug(string name,int inprice,int outprice):Item(inprice,out price)
		void bloodUsed();		//���� 
		void refineUsed();		//���� 
		void immuneUsed();		//ʥ�� 
	private:
		string name; 
		
} 
class Weapon:public Item	//���� 
{
	public:
		Weapon(string name,int ATK,int skillATK,int debuffATK,int inprice,int outprice):Item(inprice,outprice)
	private:
		string name;
		int ATK;			//������ 
		int skillATK;		//���ܸ��� 
		int debuffATK;		//����״̬ 
}
class Defence:public Item	//���� 
{
	public:
		Defence(string name,int addMHP,double defend,double miss,int inprice,int outprice):Item(inprice,outprice)
	private:
		string name;
		int addMHP;
		double defend;
		double miss;
}
class Epic:public Item		//ʷʫʥ��
{
	public:
		Epic(string name,int inprice,int outprice):Item(inprice,outprice)
	private:
		string name;
} 
Weapon weapons[11];
weapons[0]=Weapon("�ƾɵ�����",3,0,0,10,2);
weapons[1]=Weapon("����",5,0,0,12,3);
weapons[2]=Weapon("����",10,0,0,16,4);
weapons[3]=Weapon("����֮��",12,0,0,20,5);
weapons[4]=Weapon("����Ȩ��",10,10,0,20,5);
weapons[5]=Weapon("�㶾ս��",13,0,5,30,7);
weapons[6]=Weapon("����֮��",30,0,0,40,10);
weapons[7]=Weapon("����սì",35,0,10,45,11);
weapons[8]=Weapon("��ʥ����",30,20,0,50,12);
weapons[9]=Weapon("��������",35,30,0,60,15);
weapons[10]=Weapon("ʥ��",70,80,0,100,50);
Defence defences[6];
defences[0]=Defence("����",0,0.15,0,8,2);
defences[1]=Defence("�ȷ��",30,0.15,0,12,3);
defences[2]=Defence("���ּ�",50,0.2,0.1,20,5);
defences[3]=Defence("����",200,0.25,0,30,7);
defences[4]=Defence("��˪֮��",150,0.25,0.15,40,10);
defences[5]=Defence("����ս��",300,0.25,0.20,55,12);
Epic epics=Epic("���֮��",20,5);
Drug drugs[3]={("����ҩ��",10,3),("����ҩ��",10,3),("ʥ��ҩ��",20,5)};
int lhzj(int enemy_MHP)		//���֮�似�� ��Ŀ����������� 
{
	int addHP;
	addHP=enemy_MHP*2/10;
	NHP+=addHP;
	if(NHP>MHP)NHP=MHP;
	return(NHP)
}

