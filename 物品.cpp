class Item
{
	public:
		Item(int inprice=0,int outprice=0);
		int getnum{return num;}
		void get{num++;}	//获得物品 
		void lose{num--;}	//失去物品 
	private:
		int inprice;		//物品购买价格 
		int outprice;		//物品出售价格 
		int num=0;			//物品拥有数量 
}
class Drug:public Item		//药品 
{
	public:
		Drug(string name,int inprice,int outprice):Item(inprice,out price)
		void bloodUsed();		//生命 
		void refineUsed();		//净化 
		void immuneUsed();		//圣灵 
	private:
		string name; 
		
} 
class Weapon:public Item	//武器 
{
	public:
		Weapon(string name,int ATK,int skillATK,int debuffATK,int inprice,int outprice):Item(inprice,outprice)
	private:
		string name;
		int ATK;			//攻击力 
		int skillATK;		//技能附加 
		int debuffATK;		//负面状态 
}
class Defence:public Item	//防具 
{
	public:
		Defence(string name,int addMHP,double defend,double miss,int inprice,int outprice):Item(inprice,outprice)
	private:
		string name;
		int addMHP;
		double defend;
		double miss;
}
class Epic:public Item		//史诗圣物
{
	public:
		Epic(string name,int inprice,int outprice):Item(inprice,outprice)
	private:
		string name;
} 
Weapon weapons[11];
weapons[0]=Weapon("破旧的铁剑",3,0,0,10,2);
weapons[1]=Weapon("铁剑",5,0,0,12,3);
weapons[2]=Weapon("阔刀",10,0,0,16,4);
weapons[3]=Weapon("诅咒之刃",12,0,0,20,5);
weapons[4]=Weapon("奥术权杖",10,10,0,20,5);
weapons[5]=Weapon("淬毒战刃",13,0,5,30,7);
weapons[6]=Weapon("白银之锋",30,0,0,40,10);
weapons[7]=Weapon("雷霆战矛",35,0,10,45,11);
weapons[8]=Weapon("神圣法杖",30,20,0,50,12);
weapons[9]=Weapon("死神镰刀",35,30,0,60,15);
weapons[10]=Weapon("圣剑",70,80,0,100,50);
Defence defences[6];
defences[0]=Defence("布甲",0,0.15,0,8,2);
defences[1]=Defence("先锋盾",30,0.15,0,12,3);
defences[2]=Defence("精钢甲",50,0.2,0.1,20,5);
defences[3]=Defence("赤红甲",200,0.25,0,30,7);
defences[4]=Defence("冰霜之盾",150,0.25,0.15,40,10);
defences[5]=Defence("先祖战甲",300,0.25,0.20,55,12);
Epic epics=Epic("灵魂之戒",20,5);
Drug drugs[3]={("生命药剂",10,3),("净化药剂",10,3),("圣灵药剂",20,5)};
int lhzj(int enemy_MHP)		//灵魂之戒技能 （目标最大生命） 
{
	int addHP;
	addHP=enemy_MHP*2/10;
	NHP+=addHP;
	if(NHP>MHP)NHP=MHP;
	return(NHP)
}

