#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
class Toglogch{
	private:
		int ID;
		string clubin_ner;
		bool hol; // true bol baruun false bol zuun
	public:
		static int count;
		string ner;
		int huch;
		int chadvar;
		Toglogch(){
		}
		~Toglogch(){

		}
		bool insert(string ner_, int huch_, int chadvar_, bool hol_){
			count ++;
			ID = count;
			ner = ner_;
			huch = huch_;
			chadvar = chadvar_;
			hol = hol_;
			clubin_ner = "Чөлөөт агент";
			return true;
		}
		bool changeClub(string bagiin_ner_){
			clubin_ner = bagiin_ner_;
			// cout << ner << " нь " << clubin_ner << "д орлоо."<< endl; 
			return true;
		}
		bool leaveClub(){
			clubin_ner = "Чөлөөт агент";
			return 0;
		}
		bool setHuch(int huch_){
			huch = huch_;
			return true;
		}
		void printer(){
			cout << "Тоглогчийн нэр: " << ner << endl;
			cout << "Тоглогчийн ID: " << ID << endl;
			cout << "Хүч: " << huch << endl;
			cout << "Чадвар: " << chadvar << endl;
			if(hol){
				cout << "Тоглодог хөл: " << "Баруун" << endl;
			}else{
				cout << "Тоглодог хөл: " << "Зүүн" << endl;
			}
			cout << "Тоглодог Клуб: " << clubin_ner << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		}
		int getBolomj(){
			return (huch + chadvar)/2;
		}
		friend class Bag;
};

class Bag{
	private:
		Toglogch a[20];
		string bagiin_ner;
		int count;
	public:
		Bag(){

		}
		~Bag(){

		}
		bool insert(string bagiin_ner_){
			bagiin_ner = bagiin_ner_;
			count = 0;
			return true;
		}
		bool add_player(Toglogch h){
			if(h.changeClub(bagiin_ner)){
				a[count] = h;
				count ++;
				return true;
			}
			else{
				return false;
			}
		}
		bool remove_player(Toglogch t){
			for (int i = 0; i < count; i++){
				if (a[i].ner == t.ner){
					t.leaveClub();
					count --;
					return true;
				}
			}
		}
		double Bagiin_bolomj(){
			double all = 0.0;
			for (int i = 0; i < count; i++)
			{
				all = all + a[i].getBolomj() ;
			}
			return all/count;
		}
		void printer(){
			// cout << count;
			cout << "Багийн нэр: " << bagiin_ner << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			for (int i = 0; i < count; i++)
			{
				a[i].printer();
			}	
		}
		void printer_player(int i){
			a[i].printer();
		}
		void printer_club_name(){
			cout << "Багийн нэр: " << bagiin_ner << endl; 
		}
};
void Toglolt(Bag a, Bag b){ // a bag yalah bol 1 iig b yalah bol 2iig tentseh bol 3 iig 
	if(a.Bagiin_bolomj() > b.Bagiin_bolomj()){
		a.printer_club_name();
	}
	if(a.Bagiin_bolomj() < b.Bagiin_bolomj()){
		b.printer_club_name();
	}
	if(a.Bagiin_bolomj() == b.Bagiin_bolomj()){
		cout << "Тэнцээ" << endl;
	}
}
void select_Toglogch(string ner_){

}
int Toglogch::count = 0;
int main(){
	// Uzuulelt a;
	// a.insert(12, 23);
	// a.printer();
	// Toglogch a;
	// a.insert("Bataa",87,75);
	// a.printer();
	// Bag a;
	// a.insert("monhiin bag");
	// a.add_player("Bataa",87,75);
	Toglogch t1,t2,t3,t4;
	t1.insert("Батаа",87,75,true);
	t2.insert("Доржоо",81,100,false);
	t3.insert("Сансиро",60,75,false);
	t4.insert("САНСар",81,99,false);
	t1.setHuch(95);
	// t1.printer();
	Bag a;
	a.insert("Мөнхийн баг");
	a.add_player(t1);
	a.add_player(t2);
	// a.remove_player(t1);
	// a.printer();
	Bag b;
	b.insert("Сансарын баг");
	b.add_player(t3);
	b.add_player(t4);
	// b.add_player(t1);
	// b.printer_player(2);
	// b.printer();
	// t1.printer();

	// cout << a.Bagiin_bolomj();
	// cout << b.Bagiin_bolomj();
	Toglolt(a,b);
	// select_Toglogch("Сансиро");
	// cout << Toglogch::count;
	return 0;
}
