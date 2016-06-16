package leetcode;

/*   ≈‰∆˜ƒ£ Ω  */
public class GooseAdapter implements Quackable {
	Goose goose;
	
	public GooseAdapter(Goose goose) {
		// TODO Auto-generated constructor stub
		this.goose = goose;
	}
	
	public void quack() {
		goose.honk();
	}
}
