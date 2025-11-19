// =======Using hash table 
// C#
public class Solution
{
    public IList<IList<string>> GroupAnagrams(string[] strs)
    {
        var mapper = new Dictionary<string, IList<string>>();

        foreach (string s in strs)
        {
            // Convert to char array
            char[] chars = s.ToCharArray();
            Array.Sort(chars);
            //Reconstruct sorted string
            string key = new string(chars);

            if (!mapper.ContainsKey(key))
            {
                mapper[key] = new List<string>(); //similar to vector<string> in C++
            }
            mapper[key].Add(s); //add the original string using the anagram string
        }

        return mapper.Values.ToList();
    }
}

//C++
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;

        for (auto &s : strs){
            string word = s;
            sort(word.begin(), word.end());
            map[word].push_back(s); // save anagram, remove duplicates
        }
        
        vector<vector<string>> result;
        for (auto &s : map){
            //now return anagram by grouping
            result.push_back(s.second); //return vectors of strings
        }
        return result;
    }
};

//========== Using LINQ
public class Solution {
    public IList<IList<string>> GroupAnagrams(string[] strs) {
        return strs
            .GroupBy(s=> new string(s.OrderBy(c=>c).ToArray())) //Sort all element str of strs to group them
            .Select(g=> g.ToList() as IList<string>)
            .ToList();
    }
}
