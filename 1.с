using System.Text;
using TestTasks;

internal class Program
{
    private static void Main(string[] args)
    {
        const string FILENAME = @"C:\repository\TestTasks\Text.txt";
        var filePath = File.ReadAllText(FILENAME, Encoding.UTF8);
        if (filePath != null) //проверка на пустой файл
        {
            var textDictionary = new Lib();
            var wordDictionary = textDictionary.ConvertToDictionary(filePath);
            using var uniqueWords = new StreamWriter(@"C:\repository\TestTasks\WordsInText.txt");
            {
                foreach (var i in
                         wordDictionary.OrderByDescending(x => x.Value))
                    uniqueWords.WriteLine($"{i.Key} - {i.Value}"); //Вывод словаря в текстовый файл
            }
        }
        else
        {
            Console.WriteLine("Пустой документ");
        }
    }
}

namespace TestTasks;

public class Lib
{
    public Dictionary<string, int> ConvertToDictionary(string filePath)
    {
        var answerBook = new Dictionary<string, int>();
        char[] splitChars =
        {
            ' ', ',', '.', ':', '\t', '<', '>', '\n', ')', '(', '!', '?', ';', '"', ']', '[', '/', '-', '*'
        }; //разделители
        var words = filePath.Split(splitChars).Select(word => word.ToLower()).ToArray();
        //Split - разбивает строку на подстроки            
        //ToLower - возвращает строку в нижнем регистре
        var wordsItem = words.Distinct().ToArray();
        //Distinct - возвращает уникальные строки
        foreach (var item in wordsItem)
        {
            var count = 0;
            count = words.Where(word => word.Equals(item)).Count();
            //подсчет одинаковых строк
            answerBook.Add(item, count);
        }

        return answerBook;
    }
}
