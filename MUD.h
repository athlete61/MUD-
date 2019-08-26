#ifndef MUD_H
#define NUD_H
#include<vector>
#include<string>
#include<ctime>
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

class Role {
	protected:
		string name;
		double MHP;
        double NHP;           //当前生命值
		double Wealth;        //玩家表示拥有的金币，怪物表示死后掉落的金币
		double ATK;           //攻击力
		double Dodge;         //闪避
		bool isToxic;         //中毒与否
        double magicDamage = 0;   //法术伤害
        double experience = 0;    //玩家表示该等级的当前经验值，怪物表示死后奖励给玩家的经验值
        bool isdead = false;       

	public:
		Role(string name):
                name(name),MHP(100),NHP(100),Wealth(0),ATK(10),Dodge(0){}
        double& getExperience(){return experience;}
        double& getWealth(){return Wealth;}
        virtual ~Role() = 0;                //虚基类
};
class Player;
class Goods{                        //物品基类
    protected:
        string name;
        double price;
        enum Type{weapons,armors,drugs};//枚举以区分表示物品类型
        int type;//具体的类型
        /*string weaponsOfMname[8] = {"破旧的铁剑","铁剑","阔刀","诅咒之刃","奥术权杖","白银之锋","雷霆战矛","神圣法杖"};
        string armorsOfMname[4] = {"布甲","先锋盾","赤红甲","冰霜之盾"};
        string weaponsOfMname[2] = {"淬毒战刃","死神镰刀"};
        string armorsOfSname[2] = {"先祖战甲","精钢甲"};
        string jewelry[2] = {"灵魂之戒","玲珑心"};*/
    public:
        Goods(string name,int type,double price = 0):name(name),price(price),type(type){}
        double getPrice(){return price;}
        string getName(){return name;}
        int getType(){return type;}
        void soldBy(Player& p){p.getWealth() += price;}
        void picked(Player* p){p -> pick(this);}

        virtual void useTo(Player& p) = 0;
        virtual void show() = 0;
};

class Weapons: public Goods{
    private:
        double ATK;                 //攻击加成
        string magicName;           //法术名称
        double magicDamage;          //法术伤害
    public:
        Weapons(string name, int type, double atk, double price = 0, string mName = " ", 
                double mDamage = 0):
                Goods(name,type,price),
                ATK(atk),magicName(mName),magicDamage(mDamage){}
        double getATK(){return ATK;}
        double getMD(){return magicDamage;}
        void useTo(Player& p){p.use(this);}  //被角色使用

        void show();  //显示属性      
};

class Armors: public Goods{
    private:
        double HP;//生命值加成
        double physicalExsistance;//物理抗性
        double dodge; //闪避
    public:
        Armors(string name,int type,double Hp, double PE, double price = 0, double dodge = 0):
                Goods(name,type,price),HP(Hp),physicalExsistance(PE),dodge(dodge){}
        void useTo(Player& p){p.use(this);} //被角色使用 
        double getHP(){return HP;}
        double getPE(){return physicalExsistance;}
        double getDodge(){return dodge;}

        void show();  //显示属性

};

class Drugs:public Goods{
    private:
        enum Type{life,madness,cleansing,holy};//药剂四种类型：生命，狂暴，净化，圣灵
                            //分别为生命＋20，攻击+15，消除异常状态（中毒），免疫异常状态5回合
        int typeOfDrug;
    public:
        Drugs(string name,int type,int typeOfdrug,double price = 0):
            Goods(name,type,price),typeOfDrug(typeOfdrug){}
        void useTo(Player& p){p.use(this);}  //被角色使用
        int getType(){return typeOfDrug;}

        void show();  //展示功效
};
class Monster;
class Player: public Role{           //玩家类
    private:
        int level;                      //玩家等级          
        vector<Goods*> bag;             //玩家的背包
        double physicalExsistance;      //物理抗性
        int immuneTimes = 0;
        bool isWearingWeapon = false;   //是否已穿戴装备
        bool isWearingArmor = false;    //同上       
        enum Type{life,madness,cleansing,holy}; //药品类型
    public:
        Player(string name):Role(name), level(1),physicalExsistance(0){}
        void pick(Goods* g){bag.push_back(g);}
        void buy(Goods* g){
            bag.push_back(g);
            this -> getWealth() -= g -> getPrice();
        }
        double getDodge(){return Dodge;}
        void attack(Monster& m){m.hurt(ATK + magicDamage,this);}
        int getLength(){return bag.size();}
        Goods* getContent(int n){return bag[n];}

        void hurt(double ATK,double MD){};
        void showBag();
        void use(Weapons* w);
        void use(Armors* a);
        void use(Drugs* d);
};

class Monster: public Role{
    private:
        enum Type{weapons,armors,drugs};
        enum goodsLevel{low,high,boss};
        int glevel;
        vector<Goods*> lowReward = {
            new Weapons("铁剑",weapons,7,75), new Weapons("阔刀",weapons,11,90),
            new Weapons("诅咒之刃",weapons,13,100), new Weapons("奥术权杖",weapons,12,95),
            new Armors("布甲",armors,10,0.15,30), new Armors("先锋盾",armors,30,0.15,80)
        };
        vector<Goods*> highReward = {
            new Weapons("白银之锋",weapons,30,300), new Weapons("雷霆战矛",weapons,35,450,"技能:触电",10),
            new Weapons("神圣法杖",weapons,30,500,"技能:秘术",15),
            new Armors("赤红甲",200,0.25,600), new Armors("冰霜之盾",150,0.25,500,15)
        };
    public:
        Monster(string name,int level):Role(name),glevel(level){
            if(glevel = low)
                experience = 50 + rand() % 50;
            else if(glevel = high)
                experience = 300 + rand() % 100;
        }
        void attack(Player& p){p.hurt(ATK,magicDamage);}
        Goods* reward(int n){
            if(glevel = low)
                return lowReward[n];
            else if(glevel = high)
                return highReward[n];
        }

        void hurt(double ATK,Player* p){} //受到伤害，HP=0时一定概率掉落随机装备


};

class Store{
    private:
        enum Type{weapons,armors,drugs};
        enum Type{life,madness,cleansing,holy};
        vector<Goods*> store ={
            new Weapons("淬毒战刃", weapons, 13, 120, "剧毒", 5),
            new Weapons("死神镰刀", weapons, 30, 400, "死神呓语",15),
            new Armors("精钢甲", armors, 50, 0.2, 200, 10),
            new Armors("先祖战甲", armors, 300, 0.3, 100, 20),
            new Drugs("生命药剂", drugs, life, 50),
            new Drugs("狂暴药剂", drugs, madness, 50),
            new Drugs("净化药剂", drugs, cleansing, 50),
            new Drugs("圣灵药剂", drugs, holy,50)
        };
    public:
        Store(){}
        int getLength(){return store.size();}
        Goods* getContent(int n){return store[n];}
        void sellTo(Player& p, int n){p.buy(store[n]);}
        void show();
};

#endif
