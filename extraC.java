package library;

import library.*;

public class Task3 {

	/**
	 * Please write this method to return a Table object containing the columns
	 * songname, artist, and timesplayed for all entries which have a rating above 3,
	 * were written after the year 2009, and belong to the genre pop. Also include
	 * all songs by the artist "Dude". The result should be sorted from high timesplayed
	 * to low timesplayed.
	 * 
	 * 
	 * Table information:
	 * 
	 * - charts - 
	 * 
	 * id (int) | songname (String) | artist (String) | rating
	 * (int) | year (int) | genre (string) | timesplayed (int)
	 * 
	 * Use the technique shown to you in the samples given
	 * 
	 */
	public Table query(Table charts) throws Exception {
		
		// Your Code here
 
		charts.outputTable();
 
		 
	//	SELECT make, model, year, licenseplatenumber, registrationyear " 
    // + "FROM cars WHERE year < 2015 ORDER BY year ASC"); 
		
		Query artistQ = new Query();
		
		artistQ.Prepare("SELECT songname, artist,timesplayed FROM charts WHERE timesplayed > 3 and year > 2009 and genre = 'pop'");
		
		Query dudeQ = new Query();
	
		dudeQ.Prepare("SELECT songname, artis, timesplayed FROM charts WHERE artis = 'Dude'");
 
		Table dudes = charts.Search(dudeQ); 
 
		Table artists = charts.Search(artistQ);
  
		Query finalChart = new Query(); 
 
 		finalChart.Prepare("SELECT songname, artist, timesplayed " 
     		+ "FROM artist JOIN dudes ORDER BY timesplayed DESC"); 
  
 		Table finalTable = charts.Search(finalChart, dudes); 
		
 
		artists.outputTable(); 
 
 
 
		return null;
	}

}