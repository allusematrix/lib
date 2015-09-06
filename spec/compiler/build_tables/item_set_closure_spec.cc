#include "compiler/compiler_spec_helper.h"
#include "compiler/prepared_grammar.h"
#include "compiler/build_tables/item_set_closure.h"
#include "compiler/build_tables/item_set_transitions.h"

using namespace build_tables;
using namespace rules;

START_TEST

describe("item_set_closure", []() {
  SyntaxGrammar grammar{{
    {
      "E",
      seq({
        i_sym(1),
        i_token(11),
      }),
      RuleEntryTypeNamed,
    },
    {
      "T",
      seq({
        i_token(12),
        i_token(13),
      }),
      RuleEntryTypeNamed,
    },
  }, {}, {}};

  it("adds items at the beginnings of referenced rules", [&]() {
    ParseItemSet item_set = item_set_closure(
      ParseItem(Symbol(0), grammar.rules[0].rule, {}),
      set<Symbol>({ Symbol(10, true) }),
      grammar
    );

    AssertThat(item_set, Equals(ParseItemSet({
      {
        ParseItem(Symbol(1), grammar.rules[1].rule, {}),
        set<Symbol>({ Symbol(11, true) }),
      },
      {
        ParseItem(Symbol(0), grammar.rules[0].rule, {}),
        set<Symbol>({ Symbol(10, true) }),
      },
    })));
  });
});

END_TEST
