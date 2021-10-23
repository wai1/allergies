#include "allergies.h"

namespace allergies {
	allergy_test::allergy_test(const int& score)
	{
		const static std::unordered_map<int, std::string> allergen_score_map{
			{ 1, "eggs" },
			{2, "peanuts"},
			{4, "shellfish"},
			{8, "strawberries"},
			{16, "tomatoes"},
			{32, "chocolate"},
			{64, "pollen"},
			{128, "cats"}
		};

		for (auto allergen : allergen_score_map)
			if ((score & allergen.first) == allergen.first)
				allergies.insert({ allergen.second });
	}

	bool allergy_test::is_allergic_to(const std::string& allergen) const
	{
		return allergies.count(allergen);
	}

	std::unordered_set<std::string> allergy_test::get_allergies() const
	{
		return allergies;
	}
}  // namespace allergies
