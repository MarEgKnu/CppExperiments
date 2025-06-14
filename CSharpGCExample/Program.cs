
using CSharpGCExample;



static void MakePerson()
{
    using (Person person = new Person(10))
    {
        Console.WriteLine("Using person");
    }
}

MakePerson();




Console.Read();