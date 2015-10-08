
public class WrapTextUtils {
	public static String wrapText(String text, int maxCharsPerLine){
		//check edge cases
		if (maxCharsPerLine<1)
			return null;
		//conver string to char for better iteration performance
		char[] chars = text.toCharArray();
		
		//initialize the return object
		StringBuilder res= new StringBuilder();
		
		//used to keep track of the state
		int wordCount=0;
		int lineCount=0;
		//used to build the current word
		StringBuilder word= new StringBuilder();
		
		for (char c: chars){
			switch(c){
				//the current char means either a newline is found
				//or a word is built
				case '\n':	
				case ' ':
					//add the current word
					if(lineCount>0 &&wordCount>0)
						res.append(" ");
					if(wordCount>0)
						res.append(word);
					//if it is a newline, then add newline, update state
					if(c=='\n'){
						res.append("\n");
						lineCount=0;
					}
					//not a newline, update the state
					else{
						lineCount+=wordCount;
					}
					//clean the current word after it is added to res
					wordCount=0;
					word = new StringBuilder();
					break;
					
				//nothing special, keep building the word	
				default:
					//if the word is too big, broke it up
					//and update the state
					if(maxCharsPerLine <= wordCount){
						res.append(word+"\n");
						word = new StringBuilder();
						wordCount=0;
					}
					word.append(c);
					wordCount++;
					break;
			}
			//if adding current word would exceeds the limit,
			//starts with a newline and update the state
			if(maxCharsPerLine<lineCount+wordCount){
				res.append("\n");
				lineCount=0;
			}
		}
		//if the last word does not end with space or newline,
		//we should add it 
		if(lineCount>0 &&wordCount>0)
			res.append(" ");
		if(wordCount>0)
			res.append(word);
		
		return res.toString();
	}
	
	//this is a second approach using String split.
	//It is logically easier to write and understand
	//however, it may be slower and inflexible.
	public static String wrapText2(String text, int maxCharsPerLine){
		//check edge cases;
		if (maxCharsPerLine<1)
			return null;
		//initialize the return value
		StringBuilder res = new StringBuilder();
		//get original lines from text
		String[] lines = text.split("\n");
		
		for(String line:lines){
			//get words from each line
			String[] words = line.split(" ");
			//keep track of the chars per line.
			int count =0;
			for(String word: words){
				//skip multiple spaces
				if(!word.isEmpty()){
					//if the single word too big, broke it up
					while(word.length()>maxCharsPerLine){
						//need to change line if the line
						//already contains something.
						if(count>0){
							res.append("\n");
							count=0;
						}
						//partition the word and add it to res,update res
						res.append(word.substring(0,maxCharsPerLine));
						word= word.substring(maxCharsPerLine);

						count+=maxCharsPerLine;
					}
					//if adding the word exceeds the limit, break a line
					if(word.length()+count>maxCharsPerLine){
						res.append("\n");
						count=0;
					}
					
					//normal cases, add the word
					if(count>0)
						res.append(" ");
					res.append(word);
					count+=word.length();
				}
			}
			//the work for this line is done
			res.append("\n");
		}
		//adding last word will have an extra '\n', remove it.
		res.deleteCharAt(res.length()-1);
		return res.toString();
	}
	public static void main(String[] args)
	{
		String text = " abc c \n d eff \ng hic ";
		String res = wrapText(text,2);
		String res2 = wrapText2(text,2);
		System.out.println(res2);
		System.out.println(res);
		if(res.equals(res2))
			System.out.println("yes");
	}
}
