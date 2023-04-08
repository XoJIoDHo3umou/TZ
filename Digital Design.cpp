//Задание 2


using System.Text;
using Test;

internal class Program
{
    private static void Main(string[] args)
    {
        const string FILENAME = @"C:\Hitory\Test\Text.txt";
        var filePath = File.ReadAllText(FILENAME, Encoding.UTF8);
        if (filePath != null) 
        {
            var textDictionary = new Lib();
            var wordDictionary = textDictionary.ConvertToDictionary(filePath);
            using var uniqueWords = new StreamWriter(@"C:\Hitory\Test\WordsInText.txt");
            {
                foreach (var i in
                         wordDictionary.OrderByDescending(x => x.Value))
                    uniqueWords.WriteLine($"{i.Key} - {i.Value}");
            }
        }
        else
        {
            Console.WriteLine("Пустой документ");
        }
    }
}

namespace Test;

public class Lib
{
    public Dictionary<string, int> ConvertToDictionary(string filePath)
    {
        var answerBook = new Dictionary<string, int>();
        char[] splitChars =
        {
            ' ', ',', '.', ':', '\t', '<', '>', '\n', ')', '(', '!', '?', ';', '"', ']', '[', '/', '-', '*'
        }; 
        var words = filePath.Split(splitChars).Select(word => word.ToLower()).ToArray();
        var wordsItem = words.Distinct().ToArray();
        foreach (var item in wordsItem)
        {
            var count = 0;
            count = words.Where(word => word.Equals(item)).Count();
            answerBook.Add(item, count);
        }

        return answerBook;
    }
}
