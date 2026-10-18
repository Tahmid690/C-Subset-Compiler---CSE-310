
// Generated from CSubset_2205009.g4 by ANTLR 4.13.2


#include "CSubset_2205009Visitor.h"

#include "CSubset_2205009Parser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct CSubset_2205009ParserStaticData final {
  CSubset_2205009ParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  CSubset_2205009ParserStaticData(const CSubset_2205009ParserStaticData&) = delete;
  CSubset_2205009ParserStaticData(CSubset_2205009ParserStaticData&&) = delete;
  CSubset_2205009ParserStaticData& operator=(const CSubset_2205009ParserStaticData&) = delete;
  CSubset_2205009ParserStaticData& operator=(CSubset_2205009ParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag csubset_2205009ParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<CSubset_2205009ParserStaticData> csubset_2205009ParserStaticData = nullptr;

void csubset_2205009ParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (csubset_2205009ParserStaticData != nullptr) {
    return;
  }
#else
  assert(csubset_2205009ParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<CSubset_2205009ParserStaticData>(
    std::vector<std::string>{
      "start", "program", "unit", "func_declaration", "func_definition", 
      "parameter_list", "compound_statement", "var_declaration", "type_specifier", 
      "declaration_list", "statements", "statement", "expression_statement", 
      "variable", "expression", "logic_expression", "rel_expression", "simple_expression", 
      "term", "unary_expression", "factor", "argument_list", "arguments"
    },
    std::vector<std::string>{
      "", "", "", "", "", "'if'", "'else'", "'for'", "'while'", "'println'", 
      "'return'", "'int'", "'float'", "'void'", "'('", "')'", "'{'", "'}'", 
      "'['", "']'", "';'", "','", "", "", "'++'", "'--'", "'!'", "", "", 
      "'='"
    },
    std::vector<std::string>{
      "", "LINE_COMMENT", "BLOCK_COMMENT", "STRING", "WS", "IF", "ELSE", 
      "FOR", "WHILE", "PRINTLN", "RETURN", "INT", "FLOAT", "VOID", "LPAREN", 
      "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "SEMICOLON", "COMMA", 
      "ADDOP", "MULOP", "INCOP", "DECOP", "NOT", "RELOP", "LOGICOP", "ASSIGNOP", 
      "ID", "CONST_INT", "CONST_FLOAT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,32,315,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,1,0,1,0,1,1,1,1,1,1,1,1,1,1,5,1,54,8,1,10,1,12,1,57,9,1,
  	1,2,1,2,1,2,3,2,62,8,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	3,1,3,3,3,77,8,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,
  	3,4,92,8,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,3,5,102,8,5,1,5,1,5,1,5,1,
  	5,1,5,1,5,1,5,1,5,5,5,112,8,5,10,5,12,5,115,9,5,1,6,1,6,1,6,1,6,1,6,1,
  	6,3,6,123,8,6,1,7,1,7,1,7,1,7,1,8,1,8,1,8,3,8,132,8,8,1,9,1,9,1,9,1,9,
  	1,9,1,9,3,9,140,8,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,5,
  	9,154,8,9,10,9,12,9,157,9,9,1,10,1,10,1,10,1,10,1,10,5,10,164,8,10,10,
  	10,12,10,167,9,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,
  	11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,
  	11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,
  	11,1,11,3,11,209,8,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,3,
  	12,220,8,12,1,13,1,13,1,13,1,13,1,13,1,13,3,13,228,8,13,1,14,1,14,1,14,
  	1,14,1,14,3,14,235,8,14,1,15,1,15,1,15,1,15,1,15,3,15,242,8,15,1,16,1,
  	16,1,16,1,16,1,16,3,16,249,8,16,1,17,1,17,1,17,1,17,1,17,1,17,5,17,257,
  	8,17,10,17,12,17,260,9,17,1,18,1,18,1,18,1,18,1,18,1,18,5,18,268,8,18,
  	10,18,12,18,271,9,18,1,19,1,19,1,19,1,19,1,19,3,19,278,8,19,1,20,1,20,
  	1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,
  	1,20,1,20,3,20,298,8,20,1,21,1,21,3,21,302,8,21,1,22,1,22,1,22,1,22,1,
  	22,1,22,5,22,310,8,22,10,22,12,22,313,9,22,1,22,0,7,2,10,18,20,34,36,
  	44,23,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,
  	0,0,334,0,46,1,0,0,0,2,48,1,0,0,0,4,61,1,0,0,0,6,76,1,0,0,0,8,91,1,0,
  	0,0,10,101,1,0,0,0,12,122,1,0,0,0,14,124,1,0,0,0,16,131,1,0,0,0,18,139,
  	1,0,0,0,20,158,1,0,0,0,22,208,1,0,0,0,24,219,1,0,0,0,26,227,1,0,0,0,28,
  	234,1,0,0,0,30,241,1,0,0,0,32,248,1,0,0,0,34,250,1,0,0,0,36,261,1,0,0,
  	0,38,277,1,0,0,0,40,297,1,0,0,0,42,301,1,0,0,0,44,303,1,0,0,0,46,47,3,
  	2,1,0,47,1,1,0,0,0,48,49,6,1,-1,0,49,50,3,4,2,0,50,55,1,0,0,0,51,52,10,
  	2,0,0,52,54,3,4,2,0,53,51,1,0,0,0,54,57,1,0,0,0,55,53,1,0,0,0,55,56,1,
  	0,0,0,56,3,1,0,0,0,57,55,1,0,0,0,58,62,3,14,7,0,59,62,3,6,3,0,60,62,3,
  	8,4,0,61,58,1,0,0,0,61,59,1,0,0,0,61,60,1,0,0,0,62,5,1,0,0,0,63,64,3,
  	16,8,0,64,65,5,30,0,0,65,66,5,14,0,0,66,67,3,10,5,0,67,68,5,15,0,0,68,
  	69,5,20,0,0,69,77,1,0,0,0,70,71,3,16,8,0,71,72,5,30,0,0,72,73,5,14,0,
  	0,73,74,5,15,0,0,74,75,5,20,0,0,75,77,1,0,0,0,76,63,1,0,0,0,76,70,1,0,
  	0,0,77,7,1,0,0,0,78,79,3,16,8,0,79,80,5,30,0,0,80,81,5,14,0,0,81,82,3,
  	10,5,0,82,83,5,15,0,0,83,84,3,12,6,0,84,92,1,0,0,0,85,86,3,16,8,0,86,
  	87,5,30,0,0,87,88,5,14,0,0,88,89,5,15,0,0,89,90,3,12,6,0,90,92,1,0,0,
  	0,91,78,1,0,0,0,91,85,1,0,0,0,92,9,1,0,0,0,93,94,6,5,-1,0,94,95,3,16,
  	8,0,95,96,5,30,0,0,96,102,1,0,0,0,97,102,3,16,8,0,98,99,3,16,8,0,99,100,
  	5,22,0,0,100,102,1,0,0,0,101,93,1,0,0,0,101,97,1,0,0,0,101,98,1,0,0,0,
  	102,113,1,0,0,0,103,104,10,5,0,0,104,105,5,21,0,0,105,106,3,16,8,0,106,
  	107,5,30,0,0,107,112,1,0,0,0,108,109,10,4,0,0,109,110,5,21,0,0,110,112,
  	3,16,8,0,111,103,1,0,0,0,111,108,1,0,0,0,112,115,1,0,0,0,113,111,1,0,
  	0,0,113,114,1,0,0,0,114,11,1,0,0,0,115,113,1,0,0,0,116,117,5,16,0,0,117,
  	118,3,20,10,0,118,119,5,17,0,0,119,123,1,0,0,0,120,121,5,16,0,0,121,123,
  	5,17,0,0,122,116,1,0,0,0,122,120,1,0,0,0,123,13,1,0,0,0,124,125,3,16,
  	8,0,125,126,3,18,9,0,126,127,5,20,0,0,127,15,1,0,0,0,128,132,5,11,0,0,
  	129,132,5,12,0,0,130,132,5,13,0,0,131,128,1,0,0,0,131,129,1,0,0,0,131,
  	130,1,0,0,0,132,17,1,0,0,0,133,134,6,9,-1,0,134,140,5,30,0,0,135,136,
  	5,30,0,0,136,137,5,18,0,0,137,138,5,31,0,0,138,140,5,19,0,0,139,133,1,
  	0,0,0,139,135,1,0,0,0,140,155,1,0,0,0,141,142,10,5,0,0,142,143,5,21,0,
  	0,143,154,5,30,0,0,144,145,10,4,0,0,145,146,5,21,0,0,146,147,5,30,0,0,
  	147,148,5,18,0,0,148,149,5,31,0,0,149,154,5,19,0,0,150,151,10,1,0,0,151,
  	152,5,22,0,0,152,154,5,30,0,0,153,141,1,0,0,0,153,144,1,0,0,0,153,150,
  	1,0,0,0,154,157,1,0,0,0,155,153,1,0,0,0,155,156,1,0,0,0,156,19,1,0,0,
  	0,157,155,1,0,0,0,158,159,6,10,-1,0,159,160,3,22,11,0,160,165,1,0,0,0,
  	161,162,10,1,0,0,162,164,3,22,11,0,163,161,1,0,0,0,164,167,1,0,0,0,165,
  	163,1,0,0,0,165,166,1,0,0,0,166,21,1,0,0,0,167,165,1,0,0,0,168,209,3,
  	14,7,0,169,209,3,24,12,0,170,209,3,12,6,0,171,172,5,7,0,0,172,173,5,14,
  	0,0,173,174,3,24,12,0,174,175,3,24,12,0,175,176,3,28,14,0,176,177,5,15,
  	0,0,177,178,3,22,11,0,178,209,1,0,0,0,179,180,5,5,0,0,180,181,5,14,0,
  	0,181,182,3,28,14,0,182,183,5,15,0,0,183,184,3,22,11,0,184,209,1,0,0,
  	0,185,186,5,5,0,0,186,187,5,14,0,0,187,188,3,28,14,0,188,189,5,15,0,0,
  	189,190,3,22,11,0,190,191,5,6,0,0,191,192,3,22,11,0,192,209,1,0,0,0,193,
  	194,5,8,0,0,194,195,5,14,0,0,195,196,3,28,14,0,196,197,5,15,0,0,197,198,
  	3,22,11,0,198,209,1,0,0,0,199,200,5,9,0,0,200,201,5,14,0,0,201,202,5,
  	30,0,0,202,203,5,15,0,0,203,209,5,20,0,0,204,205,5,10,0,0,205,206,3,28,
  	14,0,206,207,5,20,0,0,207,209,1,0,0,0,208,168,1,0,0,0,208,169,1,0,0,0,
  	208,170,1,0,0,0,208,171,1,0,0,0,208,179,1,0,0,0,208,185,1,0,0,0,208,193,
  	1,0,0,0,208,199,1,0,0,0,208,204,1,0,0,0,209,23,1,0,0,0,210,220,5,20,0,
  	0,211,212,3,28,14,0,212,213,5,20,0,0,213,220,1,0,0,0,214,215,3,28,14,
  	0,215,216,5,22,0,0,216,217,5,29,0,0,217,218,3,28,14,0,218,220,1,0,0,0,
  	219,210,1,0,0,0,219,211,1,0,0,0,219,214,1,0,0,0,220,25,1,0,0,0,221,228,
  	5,30,0,0,222,223,5,30,0,0,223,224,5,18,0,0,224,225,3,28,14,0,225,226,
  	5,19,0,0,226,228,1,0,0,0,227,221,1,0,0,0,227,222,1,0,0,0,228,27,1,0,0,
  	0,229,235,3,30,15,0,230,231,3,26,13,0,231,232,5,29,0,0,232,233,3,30,15,
  	0,233,235,1,0,0,0,234,229,1,0,0,0,234,230,1,0,0,0,235,29,1,0,0,0,236,
  	242,3,32,16,0,237,238,3,32,16,0,238,239,5,28,0,0,239,240,3,32,16,0,240,
  	242,1,0,0,0,241,236,1,0,0,0,241,237,1,0,0,0,242,31,1,0,0,0,243,249,3,
  	34,17,0,244,245,3,34,17,0,245,246,5,27,0,0,246,247,3,34,17,0,247,249,
  	1,0,0,0,248,243,1,0,0,0,248,244,1,0,0,0,249,33,1,0,0,0,250,251,6,17,-1,
  	0,251,252,3,36,18,0,252,258,1,0,0,0,253,254,10,1,0,0,254,255,5,22,0,0,
  	255,257,3,36,18,0,256,253,1,0,0,0,257,260,1,0,0,0,258,256,1,0,0,0,258,
  	259,1,0,0,0,259,35,1,0,0,0,260,258,1,0,0,0,261,262,6,18,-1,0,262,263,
  	3,38,19,0,263,269,1,0,0,0,264,265,10,1,0,0,265,266,5,23,0,0,266,268,3,
  	38,19,0,267,264,1,0,0,0,268,271,1,0,0,0,269,267,1,0,0,0,269,270,1,0,0,
  	0,270,37,1,0,0,0,271,269,1,0,0,0,272,273,5,22,0,0,273,278,3,38,19,0,274,
  	275,5,26,0,0,275,278,3,38,19,0,276,278,3,40,20,0,277,272,1,0,0,0,277,
  	274,1,0,0,0,277,276,1,0,0,0,278,39,1,0,0,0,279,298,3,26,13,0,280,281,
  	5,30,0,0,281,282,5,14,0,0,282,283,3,42,21,0,283,284,5,15,0,0,284,298,
  	1,0,0,0,285,286,5,14,0,0,286,287,3,28,14,0,287,288,5,15,0,0,288,298,1,
  	0,0,0,289,298,5,31,0,0,290,298,5,32,0,0,291,292,3,26,13,0,292,293,5,24,
  	0,0,293,298,1,0,0,0,294,295,3,26,13,0,295,296,5,25,0,0,296,298,1,0,0,
  	0,297,279,1,0,0,0,297,280,1,0,0,0,297,285,1,0,0,0,297,289,1,0,0,0,297,
  	290,1,0,0,0,297,291,1,0,0,0,297,294,1,0,0,0,298,41,1,0,0,0,299,302,3,
  	44,22,0,300,302,1,0,0,0,301,299,1,0,0,0,301,300,1,0,0,0,302,43,1,0,0,
  	0,303,304,6,22,-1,0,304,305,3,30,15,0,305,311,1,0,0,0,306,307,10,2,0,
  	0,307,308,5,21,0,0,308,310,3,30,15,0,309,306,1,0,0,0,310,313,1,0,0,0,
  	311,309,1,0,0,0,311,312,1,0,0,0,312,45,1,0,0,0,313,311,1,0,0,0,25,55,
  	61,76,91,101,111,113,122,131,139,153,155,165,208,219,227,234,241,248,
  	258,269,277,297,301,311
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  csubset_2205009ParserStaticData = std::move(staticData);
}

}

CSubset_2205009Parser::CSubset_2205009Parser(TokenStream *input) : CSubset_2205009Parser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

CSubset_2205009Parser::CSubset_2205009Parser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  CSubset_2205009Parser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *csubset_2205009ParserStaticData->atn, csubset_2205009ParserStaticData->decisionToDFA, csubset_2205009ParserStaticData->sharedContextCache, options);
}

CSubset_2205009Parser::~CSubset_2205009Parser() {
  delete _interpreter;
}

const atn::ATN& CSubset_2205009Parser::getATN() const {
  return *csubset_2205009ParserStaticData->atn;
}

std::string CSubset_2205009Parser::getGrammarFileName() const {
  return "CSubset_2205009.g4";
}

const std::vector<std::string>& CSubset_2205009Parser::getRuleNames() const {
  return csubset_2205009ParserStaticData->ruleNames;
}

const dfa::Vocabulary& CSubset_2205009Parser::getVocabulary() const {
  return csubset_2205009ParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView CSubset_2205009Parser::getSerializedATN() const {
  return csubset_2205009ParserStaticData->serializedATN;
}


//----------------- StartContext ------------------------------------------------------------------

CSubset_2205009Parser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CSubset_2205009Parser::ProgramContext* CSubset_2205009Parser::StartContext::program() {
  return getRuleContext<CSubset_2205009Parser::ProgramContext>(0);
}


size_t CSubset_2205009Parser::StartContext::getRuleIndex() const {
  return CSubset_2205009Parser::RuleStart;
}


std::any CSubset_2205009Parser::StartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitStart(this);
  else
    return visitor->visitChildren(this);
}

CSubset_2205009Parser::StartContext* CSubset_2205009Parser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, CSubset_2205009Parser::RuleStart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(46);
    program(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramContext ------------------------------------------------------------------

CSubset_2205009Parser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubset_2205009Parser::ProgramContext::getRuleIndex() const {
  return CSubset_2205009Parser::RuleProgram;
}

void CSubset_2205009Parser::ProgramContext::copyFrom(ProgramContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- UnitRuleContext ------------------------------------------------------------------

CSubset_2205009Parser::UnitContext* CSubset_2205009Parser::UnitRuleContext::unit() {
  return getRuleContext<CSubset_2205009Parser::UnitContext>(0);
}

CSubset_2205009Parser::UnitRuleContext::UnitRuleContext(ProgramContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::UnitRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitUnitRule(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ProgUnitRuleContext ------------------------------------------------------------------

CSubset_2205009Parser::ProgramContext* CSubset_2205009Parser::ProgUnitRuleContext::program() {
  return getRuleContext<CSubset_2205009Parser::ProgramContext>(0);
}

CSubset_2205009Parser::UnitContext* CSubset_2205009Parser::ProgUnitRuleContext::unit() {
  return getRuleContext<CSubset_2205009Parser::UnitContext>(0);
}

CSubset_2205009Parser::ProgUnitRuleContext::ProgUnitRuleContext(ProgramContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::ProgUnitRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitProgUnitRule(this);
  else
    return visitor->visitChildren(this);
}

CSubset_2205009Parser::ProgramContext* CSubset_2205009Parser::program() {
   return program(0);
}

CSubset_2205009Parser::ProgramContext* CSubset_2205009Parser::program(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubset_2205009Parser::ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, parentState);
  CSubset_2205009Parser::ProgramContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, CSubset_2205009Parser::RuleProgram, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<UnitRuleContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(49);
    unit();
    _ctx->stop = _input->LT(-1);
    setState(55);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<ProgUnitRuleContext>(_tracker.createInstance<ProgramContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleProgram);
        setState(51);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(52);
        unit(); 
      }
      setState(57);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- UnitContext ------------------------------------------------------------------

CSubset_2205009Parser::UnitContext::UnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubset_2205009Parser::UnitContext::getRuleIndex() const {
  return CSubset_2205009Parser::RuleUnit;
}

void CSubset_2205009Parser::UnitContext::copyFrom(UnitContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Var_decContext ------------------------------------------------------------------

CSubset_2205009Parser::Var_declarationContext* CSubset_2205009Parser::Var_decContext::var_declaration() {
  return getRuleContext<CSubset_2205009Parser::Var_declarationContext>(0);
}

CSubset_2205009Parser::Var_decContext::Var_decContext(UnitContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Var_decContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitVar_dec(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Func_decContext ------------------------------------------------------------------

CSubset_2205009Parser::Func_declarationContext* CSubset_2205009Parser::Func_decContext::func_declaration() {
  return getRuleContext<CSubset_2205009Parser::Func_declarationContext>(0);
}

CSubset_2205009Parser::Func_decContext::Func_decContext(UnitContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Func_decContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitFunc_dec(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Func_defContext ------------------------------------------------------------------

CSubset_2205009Parser::Func_definitionContext* CSubset_2205009Parser::Func_defContext::func_definition() {
  return getRuleContext<CSubset_2205009Parser::Func_definitionContext>(0);
}

CSubset_2205009Parser::Func_defContext::Func_defContext(UnitContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Func_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitFunc_def(this);
  else
    return visitor->visitChildren(this);
}
CSubset_2205009Parser::UnitContext* CSubset_2205009Parser::unit() {
  UnitContext *_localctx = _tracker.createInstance<UnitContext>(_ctx, getState());
  enterRule(_localctx, 4, CSubset_2205009Parser::RuleUnit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(61);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubset_2205009Parser::Var_decContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(58);
      var_declaration();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubset_2205009Parser::Func_decContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(59);
      func_declaration();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CSubset_2205009Parser::Func_defContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(60);
      func_definition();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_declarationContext ------------------------------------------------------------------

CSubset_2205009Parser::Func_declarationContext::Func_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubset_2205009Parser::Func_declarationContext::getRuleIndex() const {
  return CSubset_2205009Parser::RuleFunc_declaration;
}

void CSubset_2205009Parser::Func_declarationContext::copyFrom(Func_declarationContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Funcdec_without_paramContext ------------------------------------------------------------------

CSubset_2205009Parser::Type_specifierContext* CSubset_2205009Parser::Funcdec_without_paramContext::type_specifier() {
  return getRuleContext<CSubset_2205009Parser::Type_specifierContext>(0);
}

tree::TerminalNode* CSubset_2205009Parser::Funcdec_without_paramContext::ID() {
  return getToken(CSubset_2205009Parser::ID, 0);
}

tree::TerminalNode* CSubset_2205009Parser::Funcdec_without_paramContext::LPAREN() {
  return getToken(CSubset_2205009Parser::LPAREN, 0);
}

tree::TerminalNode* CSubset_2205009Parser::Funcdec_without_paramContext::RPAREN() {
  return getToken(CSubset_2205009Parser::RPAREN, 0);
}

tree::TerminalNode* CSubset_2205009Parser::Funcdec_without_paramContext::SEMICOLON() {
  return getToken(CSubset_2205009Parser::SEMICOLON, 0);
}

CSubset_2205009Parser::Funcdec_without_paramContext::Funcdec_without_paramContext(Func_declarationContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Funcdec_without_paramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitFuncdec_without_param(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Funcdec_with_paramContext ------------------------------------------------------------------

CSubset_2205009Parser::Type_specifierContext* CSubset_2205009Parser::Funcdec_with_paramContext::type_specifier() {
  return getRuleContext<CSubset_2205009Parser::Type_specifierContext>(0);
}

tree::TerminalNode* CSubset_2205009Parser::Funcdec_with_paramContext::ID() {
  return getToken(CSubset_2205009Parser::ID, 0);
}

tree::TerminalNode* CSubset_2205009Parser::Funcdec_with_paramContext::LPAREN() {
  return getToken(CSubset_2205009Parser::LPAREN, 0);
}

CSubset_2205009Parser::Parameter_listContext* CSubset_2205009Parser::Funcdec_with_paramContext::parameter_list() {
  return getRuleContext<CSubset_2205009Parser::Parameter_listContext>(0);
}

tree::TerminalNode* CSubset_2205009Parser::Funcdec_with_paramContext::RPAREN() {
  return getToken(CSubset_2205009Parser::RPAREN, 0);
}

tree::TerminalNode* CSubset_2205009Parser::Funcdec_with_paramContext::SEMICOLON() {
  return getToken(CSubset_2205009Parser::SEMICOLON, 0);
}

CSubset_2205009Parser::Funcdec_with_paramContext::Funcdec_with_paramContext(Func_declarationContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Funcdec_with_paramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitFuncdec_with_param(this);
  else
    return visitor->visitChildren(this);
}
CSubset_2205009Parser::Func_declarationContext* CSubset_2205009Parser::func_declaration() {
  Func_declarationContext *_localctx = _tracker.createInstance<Func_declarationContext>(_ctx, getState());
  enterRule(_localctx, 6, CSubset_2205009Parser::RuleFunc_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(76);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubset_2205009Parser::Funcdec_with_paramContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(63);
      type_specifier();
      setState(64);
      match(CSubset_2205009Parser::ID);
      setState(65);
      match(CSubset_2205009Parser::LPAREN);
      setState(66);
      parameter_list(0);
      setState(67);
      match(CSubset_2205009Parser::RPAREN);
      setState(68);
      match(CSubset_2205009Parser::SEMICOLON);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubset_2205009Parser::Funcdec_without_paramContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(70);
      type_specifier();
      setState(71);
      match(CSubset_2205009Parser::ID);
      setState(72);
      match(CSubset_2205009Parser::LPAREN);
      setState(73);
      match(CSubset_2205009Parser::RPAREN);
      setState(74);
      match(CSubset_2205009Parser::SEMICOLON);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_definitionContext ------------------------------------------------------------------

CSubset_2205009Parser::Func_definitionContext::Func_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubset_2205009Parser::Func_definitionContext::getRuleIndex() const {
  return CSubset_2205009Parser::RuleFunc_definition;
}

void CSubset_2205009Parser::Func_definitionContext::copyFrom(Func_definitionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Funcdef_without_paramContext ------------------------------------------------------------------

CSubset_2205009Parser::Type_specifierContext* CSubset_2205009Parser::Funcdef_without_paramContext::type_specifier() {
  return getRuleContext<CSubset_2205009Parser::Type_specifierContext>(0);
}

tree::TerminalNode* CSubset_2205009Parser::Funcdef_without_paramContext::ID() {
  return getToken(CSubset_2205009Parser::ID, 0);
}

tree::TerminalNode* CSubset_2205009Parser::Funcdef_without_paramContext::LPAREN() {
  return getToken(CSubset_2205009Parser::LPAREN, 0);
}

tree::TerminalNode* CSubset_2205009Parser::Funcdef_without_paramContext::RPAREN() {
  return getToken(CSubset_2205009Parser::RPAREN, 0);
}

CSubset_2205009Parser::Compound_statementContext* CSubset_2205009Parser::Funcdef_without_paramContext::compound_statement() {
  return getRuleContext<CSubset_2205009Parser::Compound_statementContext>(0);
}

CSubset_2205009Parser::Funcdef_without_paramContext::Funcdef_without_paramContext(Func_definitionContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Funcdef_without_paramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitFuncdef_without_param(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Funcdef_with_paramContext ------------------------------------------------------------------

CSubset_2205009Parser::Type_specifierContext* CSubset_2205009Parser::Funcdef_with_paramContext::type_specifier() {
  return getRuleContext<CSubset_2205009Parser::Type_specifierContext>(0);
}

tree::TerminalNode* CSubset_2205009Parser::Funcdef_with_paramContext::ID() {
  return getToken(CSubset_2205009Parser::ID, 0);
}

tree::TerminalNode* CSubset_2205009Parser::Funcdef_with_paramContext::LPAREN() {
  return getToken(CSubset_2205009Parser::LPAREN, 0);
}

CSubset_2205009Parser::Parameter_listContext* CSubset_2205009Parser::Funcdef_with_paramContext::parameter_list() {
  return getRuleContext<CSubset_2205009Parser::Parameter_listContext>(0);
}

tree::TerminalNode* CSubset_2205009Parser::Funcdef_with_paramContext::RPAREN() {
  return getToken(CSubset_2205009Parser::RPAREN, 0);
}

CSubset_2205009Parser::Compound_statementContext* CSubset_2205009Parser::Funcdef_with_paramContext::compound_statement() {
  return getRuleContext<CSubset_2205009Parser::Compound_statementContext>(0);
}

CSubset_2205009Parser::Funcdef_with_paramContext::Funcdef_with_paramContext(Func_definitionContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Funcdef_with_paramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitFuncdef_with_param(this);
  else
    return visitor->visitChildren(this);
}
CSubset_2205009Parser::Func_definitionContext* CSubset_2205009Parser::func_definition() {
  Func_definitionContext *_localctx = _tracker.createInstance<Func_definitionContext>(_ctx, getState());
  enterRule(_localctx, 8, CSubset_2205009Parser::RuleFunc_definition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(91);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubset_2205009Parser::Funcdef_with_paramContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(78);
      type_specifier();
      setState(79);
      match(CSubset_2205009Parser::ID);
      setState(80);
      match(CSubset_2205009Parser::LPAREN);
      setState(81);
      parameter_list(0);
      setState(82);
      match(CSubset_2205009Parser::RPAREN);
      setState(83);
      compound_statement();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubset_2205009Parser::Funcdef_without_paramContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(85);
      type_specifier();
      setState(86);
      match(CSubset_2205009Parser::ID);
      setState(87);
      match(CSubset_2205009Parser::LPAREN);
      setState(88);
      match(CSubset_2205009Parser::RPAREN);
      setState(89);
      compound_statement();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parameter_listContext ------------------------------------------------------------------

CSubset_2205009Parser::Parameter_listContext::Parameter_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubset_2205009Parser::Parameter_listContext::getRuleIndex() const {
  return CSubset_2205009Parser::RuleParameter_list;
}

void CSubset_2205009Parser::Parameter_listContext::copyFrom(Parameter_listContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Param_without_idContext ------------------------------------------------------------------

CSubset_2205009Parser::Parameter_listContext* CSubset_2205009Parser::Param_without_idContext::parameter_list() {
  return getRuleContext<CSubset_2205009Parser::Parameter_listContext>(0);
}

tree::TerminalNode* CSubset_2205009Parser::Param_without_idContext::COMMA() {
  return getToken(CSubset_2205009Parser::COMMA, 0);
}

CSubset_2205009Parser::Type_specifierContext* CSubset_2205009Parser::Param_without_idContext::type_specifier() {
  return getRuleContext<CSubset_2205009Parser::Type_specifierContext>(0);
}

CSubset_2205009Parser::Param_without_idContext::Param_without_idContext(Parameter_listContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Param_without_idContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitParam_without_id(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Param_with_id_singleContext ------------------------------------------------------------------

CSubset_2205009Parser::Type_specifierContext* CSubset_2205009Parser::Param_with_id_singleContext::type_specifier() {
  return getRuleContext<CSubset_2205009Parser::Type_specifierContext>(0);
}

tree::TerminalNode* CSubset_2205009Parser::Param_with_id_singleContext::ID() {
  return getToken(CSubset_2205009Parser::ID, 0);
}

CSubset_2205009Parser::Param_with_id_singleContext::Param_with_id_singleContext(Parameter_listContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Param_with_id_singleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitParam_with_id_single(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Param_with_idContext ------------------------------------------------------------------

CSubset_2205009Parser::Parameter_listContext* CSubset_2205009Parser::Param_with_idContext::parameter_list() {
  return getRuleContext<CSubset_2205009Parser::Parameter_listContext>(0);
}

tree::TerminalNode* CSubset_2205009Parser::Param_with_idContext::COMMA() {
  return getToken(CSubset_2205009Parser::COMMA, 0);
}

CSubset_2205009Parser::Type_specifierContext* CSubset_2205009Parser::Param_with_idContext::type_specifier() {
  return getRuleContext<CSubset_2205009Parser::Type_specifierContext>(0);
}

tree::TerminalNode* CSubset_2205009Parser::Param_with_idContext::ID() {
  return getToken(CSubset_2205009Parser::ID, 0);
}

CSubset_2205009Parser::Param_with_idContext::Param_with_idContext(Parameter_listContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Param_with_idContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitParam_with_id(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Param_without_id_singleContext ------------------------------------------------------------------

CSubset_2205009Parser::Type_specifierContext* CSubset_2205009Parser::Param_without_id_singleContext::type_specifier() {
  return getRuleContext<CSubset_2205009Parser::Type_specifierContext>(0);
}

CSubset_2205009Parser::Param_without_id_singleContext::Param_without_id_singleContext(Parameter_listContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Param_without_id_singleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitParam_without_id_single(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Param_with_addopContext ------------------------------------------------------------------

CSubset_2205009Parser::Type_specifierContext* CSubset_2205009Parser::Param_with_addopContext::type_specifier() {
  return getRuleContext<CSubset_2205009Parser::Type_specifierContext>(0);
}

tree::TerminalNode* CSubset_2205009Parser::Param_with_addopContext::ADDOP() {
  return getToken(CSubset_2205009Parser::ADDOP, 0);
}

CSubset_2205009Parser::Param_with_addopContext::Param_with_addopContext(Parameter_listContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Param_with_addopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitParam_with_addop(this);
  else
    return visitor->visitChildren(this);
}

CSubset_2205009Parser::Parameter_listContext* CSubset_2205009Parser::parameter_list() {
   return parameter_list(0);
}

CSubset_2205009Parser::Parameter_listContext* CSubset_2205009Parser::parameter_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubset_2205009Parser::Parameter_listContext *_localctx = _tracker.createInstance<Parameter_listContext>(_ctx, parentState);
  CSubset_2205009Parser::Parameter_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, CSubset_2205009Parser::RuleParameter_list, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(101);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<Param_with_id_singleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(94);
      type_specifier();
      setState(95);
      match(CSubset_2205009Parser::ID);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<Param_without_id_singleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(97);
      type_specifier();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<Param_with_addopContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(98);
      type_specifier();
      setState(99);
      match(CSubset_2205009Parser::ADDOP);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(113);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(111);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Param_with_idContext>(_tracker.createInstance<Parameter_listContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleParameter_list);
          setState(103);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(104);
          match(CSubset_2205009Parser::COMMA);
          setState(105);
          type_specifier();
          setState(106);
          match(CSubset_2205009Parser::ID);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<Param_without_idContext>(_tracker.createInstance<Parameter_listContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleParameter_list);
          setState(108);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(109);
          match(CSubset_2205009Parser::COMMA);
          setState(110);
          type_specifier();
          break;
        }

        default:
          break;
        } 
      }
      setState(115);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Compound_statementContext ------------------------------------------------------------------

CSubset_2205009Parser::Compound_statementContext::Compound_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubset_2205009Parser::Compound_statementContext::getRuleIndex() const {
  return CSubset_2205009Parser::RuleCompound_statement;
}

void CSubset_2205009Parser::Compound_statementContext::copyFrom(Compound_statementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Compstat_emptyContext ------------------------------------------------------------------

tree::TerminalNode* CSubset_2205009Parser::Compstat_emptyContext::LCURL() {
  return getToken(CSubset_2205009Parser::LCURL, 0);
}

tree::TerminalNode* CSubset_2205009Parser::Compstat_emptyContext::RCURL() {
  return getToken(CSubset_2205009Parser::RCURL, 0);
}

CSubset_2205009Parser::Compstat_emptyContext::Compstat_emptyContext(Compound_statementContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Compstat_emptyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitCompstat_empty(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Compstat_with_statementsContext ------------------------------------------------------------------

tree::TerminalNode* CSubset_2205009Parser::Compstat_with_statementsContext::LCURL() {
  return getToken(CSubset_2205009Parser::LCURL, 0);
}

CSubset_2205009Parser::StatementsContext* CSubset_2205009Parser::Compstat_with_statementsContext::statements() {
  return getRuleContext<CSubset_2205009Parser::StatementsContext>(0);
}

tree::TerminalNode* CSubset_2205009Parser::Compstat_with_statementsContext::RCURL() {
  return getToken(CSubset_2205009Parser::RCURL, 0);
}

CSubset_2205009Parser::Compstat_with_statementsContext::Compstat_with_statementsContext(Compound_statementContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Compstat_with_statementsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitCompstat_with_statements(this);
  else
    return visitor->visitChildren(this);
}
CSubset_2205009Parser::Compound_statementContext* CSubset_2205009Parser::compound_statement() {
  Compound_statementContext *_localctx = _tracker.createInstance<Compound_statementContext>(_ctx, getState());
  enterRule(_localctx, 12, CSubset_2205009Parser::RuleCompound_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(122);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubset_2205009Parser::Compstat_with_statementsContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(116);
      match(CSubset_2205009Parser::LCURL);
      setState(117);
      statements(0);
      setState(118);
      match(CSubset_2205009Parser::RCURL);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubset_2205009Parser::Compstat_emptyContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(120);
      match(CSubset_2205009Parser::LCURL);
      setState(121);
      match(CSubset_2205009Parser::RCURL);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_declarationContext ------------------------------------------------------------------

CSubset_2205009Parser::Var_declarationContext::Var_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CSubset_2205009Parser::Type_specifierContext* CSubset_2205009Parser::Var_declarationContext::type_specifier() {
  return getRuleContext<CSubset_2205009Parser::Type_specifierContext>(0);
}

CSubset_2205009Parser::Declaration_listContext* CSubset_2205009Parser::Var_declarationContext::declaration_list() {
  return getRuleContext<CSubset_2205009Parser::Declaration_listContext>(0);
}

tree::TerminalNode* CSubset_2205009Parser::Var_declarationContext::SEMICOLON() {
  return getToken(CSubset_2205009Parser::SEMICOLON, 0);
}


size_t CSubset_2205009Parser::Var_declarationContext::getRuleIndex() const {
  return CSubset_2205009Parser::RuleVar_declaration;
}


std::any CSubset_2205009Parser::Var_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitVar_declaration(this);
  else
    return visitor->visitChildren(this);
}

CSubset_2205009Parser::Var_declarationContext* CSubset_2205009Parser::var_declaration() {
  Var_declarationContext *_localctx = _tracker.createInstance<Var_declarationContext>(_ctx, getState());
  enterRule(_localctx, 14, CSubset_2205009Parser::RuleVar_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(124);
    type_specifier();
    setState(125);
    declaration_list(0);
    setState(126);
    match(CSubset_2205009Parser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_specifierContext ------------------------------------------------------------------

CSubset_2205009Parser::Type_specifierContext::Type_specifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubset_2205009Parser::Type_specifierContext::getRuleIndex() const {
  return CSubset_2205009Parser::RuleType_specifier;
}

void CSubset_2205009Parser::Type_specifierContext::copyFrom(Type_specifierContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Type_floatContext ------------------------------------------------------------------

tree::TerminalNode* CSubset_2205009Parser::Type_floatContext::FLOAT() {
  return getToken(CSubset_2205009Parser::FLOAT, 0);
}

CSubset_2205009Parser::Type_floatContext::Type_floatContext(Type_specifierContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Type_floatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitType_float(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Type_voidContext ------------------------------------------------------------------

tree::TerminalNode* CSubset_2205009Parser::Type_voidContext::VOID() {
  return getToken(CSubset_2205009Parser::VOID, 0);
}

CSubset_2205009Parser::Type_voidContext::Type_voidContext(Type_specifierContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Type_voidContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitType_void(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Type_intContext ------------------------------------------------------------------

tree::TerminalNode* CSubset_2205009Parser::Type_intContext::INT() {
  return getToken(CSubset_2205009Parser::INT, 0);
}

CSubset_2205009Parser::Type_intContext::Type_intContext(Type_specifierContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Type_intContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitType_int(this);
  else
    return visitor->visitChildren(this);
}
CSubset_2205009Parser::Type_specifierContext* CSubset_2205009Parser::type_specifier() {
  Type_specifierContext *_localctx = _tracker.createInstance<Type_specifierContext>(_ctx, getState());
  enterRule(_localctx, 16, CSubset_2205009Parser::RuleType_specifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(131);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CSubset_2205009Parser::INT: {
        _localctx = _tracker.createInstance<CSubset_2205009Parser::Type_intContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(128);
        match(CSubset_2205009Parser::INT);
        break;
      }

      case CSubset_2205009Parser::FLOAT: {
        _localctx = _tracker.createInstance<CSubset_2205009Parser::Type_floatContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(129);
        match(CSubset_2205009Parser::FLOAT);
        break;
      }

      case CSubset_2205009Parser::VOID: {
        _localctx = _tracker.createInstance<CSubset_2205009Parser::Type_voidContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(130);
        match(CSubset_2205009Parser::VOID);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Declaration_listContext ------------------------------------------------------------------

CSubset_2205009Parser::Declaration_listContext::Declaration_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubset_2205009Parser::Declaration_listContext::getRuleIndex() const {
  return CSubset_2205009Parser::RuleDeclaration_list;
}

void CSubset_2205009Parser::Declaration_listContext::copyFrom(Declaration_listContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Dec_with_idarr_singleContext ------------------------------------------------------------------

tree::TerminalNode* CSubset_2205009Parser::Dec_with_idarr_singleContext::ID() {
  return getToken(CSubset_2205009Parser::ID, 0);
}

tree::TerminalNode* CSubset_2205009Parser::Dec_with_idarr_singleContext::LTHIRD() {
  return getToken(CSubset_2205009Parser::LTHIRD, 0);
}

tree::TerminalNode* CSubset_2205009Parser::Dec_with_idarr_singleContext::CONST_INT() {
  return getToken(CSubset_2205009Parser::CONST_INT, 0);
}

tree::TerminalNode* CSubset_2205009Parser::Dec_with_idarr_singleContext::RTHIRD() {
  return getToken(CSubset_2205009Parser::RTHIRD, 0);
}

CSubset_2205009Parser::Dec_with_idarr_singleContext::Dec_with_idarr_singleContext(Declaration_listContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Dec_with_idarr_singleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitDec_with_idarr_single(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Dec_with_id_singleContext ------------------------------------------------------------------

tree::TerminalNode* CSubset_2205009Parser::Dec_with_id_singleContext::ID() {
  return getToken(CSubset_2205009Parser::ID, 0);
}

CSubset_2205009Parser::Dec_with_id_singleContext::Dec_with_id_singleContext(Declaration_listContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Dec_with_id_singleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitDec_with_id_single(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Dec_with_idarrContext ------------------------------------------------------------------

CSubset_2205009Parser::Declaration_listContext* CSubset_2205009Parser::Dec_with_idarrContext::declaration_list() {
  return getRuleContext<CSubset_2205009Parser::Declaration_listContext>(0);
}

tree::TerminalNode* CSubset_2205009Parser::Dec_with_idarrContext::COMMA() {
  return getToken(CSubset_2205009Parser::COMMA, 0);
}

tree::TerminalNode* CSubset_2205009Parser::Dec_with_idarrContext::ID() {
  return getToken(CSubset_2205009Parser::ID, 0);
}

tree::TerminalNode* CSubset_2205009Parser::Dec_with_idarrContext::LTHIRD() {
  return getToken(CSubset_2205009Parser::LTHIRD, 0);
}

tree::TerminalNode* CSubset_2205009Parser::Dec_with_idarrContext::CONST_INT() {
  return getToken(CSubset_2205009Parser::CONST_INT, 0);
}

tree::TerminalNode* CSubset_2205009Parser::Dec_with_idarrContext::RTHIRD() {
  return getToken(CSubset_2205009Parser::RTHIRD, 0);
}

CSubset_2205009Parser::Dec_with_idarrContext::Dec_with_idarrContext(Declaration_listContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Dec_with_idarrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitDec_with_idarr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Dec_with_addopContext ------------------------------------------------------------------

CSubset_2205009Parser::Declaration_listContext* CSubset_2205009Parser::Dec_with_addopContext::declaration_list() {
  return getRuleContext<CSubset_2205009Parser::Declaration_listContext>(0);
}

tree::TerminalNode* CSubset_2205009Parser::Dec_with_addopContext::ADDOP() {
  return getToken(CSubset_2205009Parser::ADDOP, 0);
}

tree::TerminalNode* CSubset_2205009Parser::Dec_with_addopContext::ID() {
  return getToken(CSubset_2205009Parser::ID, 0);
}

CSubset_2205009Parser::Dec_with_addopContext::Dec_with_addopContext(Declaration_listContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Dec_with_addopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitDec_with_addop(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Dec_with_idContext ------------------------------------------------------------------

CSubset_2205009Parser::Declaration_listContext* CSubset_2205009Parser::Dec_with_idContext::declaration_list() {
  return getRuleContext<CSubset_2205009Parser::Declaration_listContext>(0);
}

tree::TerminalNode* CSubset_2205009Parser::Dec_with_idContext::COMMA() {
  return getToken(CSubset_2205009Parser::COMMA, 0);
}

tree::TerminalNode* CSubset_2205009Parser::Dec_with_idContext::ID() {
  return getToken(CSubset_2205009Parser::ID, 0);
}

CSubset_2205009Parser::Dec_with_idContext::Dec_with_idContext(Declaration_listContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Dec_with_idContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitDec_with_id(this);
  else
    return visitor->visitChildren(this);
}

CSubset_2205009Parser::Declaration_listContext* CSubset_2205009Parser::declaration_list() {
   return declaration_list(0);
}

CSubset_2205009Parser::Declaration_listContext* CSubset_2205009Parser::declaration_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubset_2205009Parser::Declaration_listContext *_localctx = _tracker.createInstance<Declaration_listContext>(_ctx, parentState);
  CSubset_2205009Parser::Declaration_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 18;
  enterRecursionRule(_localctx, 18, CSubset_2205009Parser::RuleDeclaration_list, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(139);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<Dec_with_id_singleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(134);
      match(CSubset_2205009Parser::ID);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<Dec_with_idarr_singleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(135);
      match(CSubset_2205009Parser::ID);
      setState(136);
      match(CSubset_2205009Parser::LTHIRD);
      setState(137);
      match(CSubset_2205009Parser::CONST_INT);
      setState(138);
      match(CSubset_2205009Parser::RTHIRD);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(155);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(153);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Dec_with_idContext>(_tracker.createInstance<Declaration_listContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleDeclaration_list);
          setState(141);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(142);
          match(CSubset_2205009Parser::COMMA);
          setState(143);
          match(CSubset_2205009Parser::ID);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<Dec_with_idarrContext>(_tracker.createInstance<Declaration_listContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleDeclaration_list);
          setState(144);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(145);
          match(CSubset_2205009Parser::COMMA);
          setState(146);
          match(CSubset_2205009Parser::ID);
          setState(147);
          match(CSubset_2205009Parser::LTHIRD);
          setState(148);
          match(CSubset_2205009Parser::CONST_INT);
          setState(149);
          match(CSubset_2205009Parser::RTHIRD);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<Dec_with_addopContext>(_tracker.createInstance<Declaration_listContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleDeclaration_list);
          setState(150);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(151);
          match(CSubset_2205009Parser::ADDOP);
          setState(152);
          match(CSubset_2205009Parser::ID);
          break;
        }

        default:
          break;
        } 
      }
      setState(157);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StatementsContext ------------------------------------------------------------------

CSubset_2205009Parser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubset_2205009Parser::StatementsContext::getRuleIndex() const {
  return CSubset_2205009Parser::RuleStatements;
}

void CSubset_2205009Parser::StatementsContext::copyFrom(StatementsContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Stat_singleContext ------------------------------------------------------------------

CSubset_2205009Parser::StatementContext* CSubset_2205009Parser::Stat_singleContext::statement() {
  return getRuleContext<CSubset_2205009Parser::StatementContext>(0);
}

CSubset_2205009Parser::Stat_singleContext::Stat_singleContext(StatementsContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Stat_singleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitStat_single(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Stat_multipleContext ------------------------------------------------------------------

CSubset_2205009Parser::StatementsContext* CSubset_2205009Parser::Stat_multipleContext::statements() {
  return getRuleContext<CSubset_2205009Parser::StatementsContext>(0);
}

CSubset_2205009Parser::StatementContext* CSubset_2205009Parser::Stat_multipleContext::statement() {
  return getRuleContext<CSubset_2205009Parser::StatementContext>(0);
}

CSubset_2205009Parser::Stat_multipleContext::Stat_multipleContext(StatementsContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Stat_multipleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitStat_multiple(this);
  else
    return visitor->visitChildren(this);
}

CSubset_2205009Parser::StatementsContext* CSubset_2205009Parser::statements() {
   return statements(0);
}

CSubset_2205009Parser::StatementsContext* CSubset_2205009Parser::statements(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubset_2205009Parser::StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, parentState);
  CSubset_2205009Parser::StatementsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 20;
  enterRecursionRule(_localctx, 20, CSubset_2205009Parser::RuleStatements, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<Stat_singleContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(159);
    statement();
    _ctx->stop = _input->LT(-1);
    setState(165);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<Stat_multipleContext>(_tracker.createInstance<StatementsContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleStatements);
        setState(161);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(162);
        statement(); 
      }
      setState(167);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

CSubset_2205009Parser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubset_2205009Parser::StatementContext::getRuleIndex() const {
  return CSubset_2205009Parser::RuleStatement;
}

void CSubset_2205009Parser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Stat_var_decContext ------------------------------------------------------------------

CSubset_2205009Parser::Var_declarationContext* CSubset_2205009Parser::Stat_var_decContext::var_declaration() {
  return getRuleContext<CSubset_2205009Parser::Var_declarationContext>(0);
}

CSubset_2205009Parser::Stat_var_decContext::Stat_var_decContext(StatementContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Stat_var_decContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitStat_var_dec(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Stat_compoundContext ------------------------------------------------------------------

CSubset_2205009Parser::Compound_statementContext* CSubset_2205009Parser::Stat_compoundContext::compound_statement() {
  return getRuleContext<CSubset_2205009Parser::Compound_statementContext>(0);
}

CSubset_2205009Parser::Stat_compoundContext::Stat_compoundContext(StatementContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Stat_compoundContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitStat_compound(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Stat_ifContext ------------------------------------------------------------------

tree::TerminalNode* CSubset_2205009Parser::Stat_ifContext::IF() {
  return getToken(CSubset_2205009Parser::IF, 0);
}

tree::TerminalNode* CSubset_2205009Parser::Stat_ifContext::LPAREN() {
  return getToken(CSubset_2205009Parser::LPAREN, 0);
}

CSubset_2205009Parser::ExpressionContext* CSubset_2205009Parser::Stat_ifContext::expression() {
  return getRuleContext<CSubset_2205009Parser::ExpressionContext>(0);
}

tree::TerminalNode* CSubset_2205009Parser::Stat_ifContext::RPAREN() {
  return getToken(CSubset_2205009Parser::RPAREN, 0);
}

CSubset_2205009Parser::StatementContext* CSubset_2205009Parser::Stat_ifContext::statement() {
  return getRuleContext<CSubset_2205009Parser::StatementContext>(0);
}

CSubset_2205009Parser::Stat_ifContext::Stat_ifContext(StatementContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Stat_ifContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitStat_if(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Stat_returnContext ------------------------------------------------------------------

tree::TerminalNode* CSubset_2205009Parser::Stat_returnContext::RETURN() {
  return getToken(CSubset_2205009Parser::RETURN, 0);
}

CSubset_2205009Parser::ExpressionContext* CSubset_2205009Parser::Stat_returnContext::expression() {
  return getRuleContext<CSubset_2205009Parser::ExpressionContext>(0);
}

tree::TerminalNode* CSubset_2205009Parser::Stat_returnContext::SEMICOLON() {
  return getToken(CSubset_2205009Parser::SEMICOLON, 0);
}

CSubset_2205009Parser::Stat_returnContext::Stat_returnContext(StatementContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Stat_returnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitStat_return(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Stat_for_loopContext ------------------------------------------------------------------

tree::TerminalNode* CSubset_2205009Parser::Stat_for_loopContext::FOR() {
  return getToken(CSubset_2205009Parser::FOR, 0);
}

tree::TerminalNode* CSubset_2205009Parser::Stat_for_loopContext::LPAREN() {
  return getToken(CSubset_2205009Parser::LPAREN, 0);
}

std::vector<CSubset_2205009Parser::Expression_statementContext *> CSubset_2205009Parser::Stat_for_loopContext::expression_statement() {
  return getRuleContexts<CSubset_2205009Parser::Expression_statementContext>();
}

CSubset_2205009Parser::Expression_statementContext* CSubset_2205009Parser::Stat_for_loopContext::expression_statement(size_t i) {
  return getRuleContext<CSubset_2205009Parser::Expression_statementContext>(i);
}

CSubset_2205009Parser::ExpressionContext* CSubset_2205009Parser::Stat_for_loopContext::expression() {
  return getRuleContext<CSubset_2205009Parser::ExpressionContext>(0);
}

tree::TerminalNode* CSubset_2205009Parser::Stat_for_loopContext::RPAREN() {
  return getToken(CSubset_2205009Parser::RPAREN, 0);
}

CSubset_2205009Parser::StatementContext* CSubset_2205009Parser::Stat_for_loopContext::statement() {
  return getRuleContext<CSubset_2205009Parser::StatementContext>(0);
}

CSubset_2205009Parser::Stat_for_loopContext::Stat_for_loopContext(StatementContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Stat_for_loopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitStat_for_loop(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Stat_printlnContext ------------------------------------------------------------------

tree::TerminalNode* CSubset_2205009Parser::Stat_printlnContext::PRINTLN() {
  return getToken(CSubset_2205009Parser::PRINTLN, 0);
}

tree::TerminalNode* CSubset_2205009Parser::Stat_printlnContext::LPAREN() {
  return getToken(CSubset_2205009Parser::LPAREN, 0);
}

tree::TerminalNode* CSubset_2205009Parser::Stat_printlnContext::ID() {
  return getToken(CSubset_2205009Parser::ID, 0);
}

tree::TerminalNode* CSubset_2205009Parser::Stat_printlnContext::RPAREN() {
  return getToken(CSubset_2205009Parser::RPAREN, 0);
}

tree::TerminalNode* CSubset_2205009Parser::Stat_printlnContext::SEMICOLON() {
  return getToken(CSubset_2205009Parser::SEMICOLON, 0);
}

CSubset_2205009Parser::Stat_printlnContext::Stat_printlnContext(StatementContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Stat_printlnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitStat_println(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Stat_whileContext ------------------------------------------------------------------

tree::TerminalNode* CSubset_2205009Parser::Stat_whileContext::WHILE() {
  return getToken(CSubset_2205009Parser::WHILE, 0);
}

tree::TerminalNode* CSubset_2205009Parser::Stat_whileContext::LPAREN() {
  return getToken(CSubset_2205009Parser::LPAREN, 0);
}

CSubset_2205009Parser::ExpressionContext* CSubset_2205009Parser::Stat_whileContext::expression() {
  return getRuleContext<CSubset_2205009Parser::ExpressionContext>(0);
}

tree::TerminalNode* CSubset_2205009Parser::Stat_whileContext::RPAREN() {
  return getToken(CSubset_2205009Parser::RPAREN, 0);
}

CSubset_2205009Parser::StatementContext* CSubset_2205009Parser::Stat_whileContext::statement() {
  return getRuleContext<CSubset_2205009Parser::StatementContext>(0);
}

CSubset_2205009Parser::Stat_whileContext::Stat_whileContext(StatementContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Stat_whileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitStat_while(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Stat_if_elseContext ------------------------------------------------------------------

tree::TerminalNode* CSubset_2205009Parser::Stat_if_elseContext::IF() {
  return getToken(CSubset_2205009Parser::IF, 0);
}

tree::TerminalNode* CSubset_2205009Parser::Stat_if_elseContext::LPAREN() {
  return getToken(CSubset_2205009Parser::LPAREN, 0);
}

CSubset_2205009Parser::ExpressionContext* CSubset_2205009Parser::Stat_if_elseContext::expression() {
  return getRuleContext<CSubset_2205009Parser::ExpressionContext>(0);
}

tree::TerminalNode* CSubset_2205009Parser::Stat_if_elseContext::RPAREN() {
  return getToken(CSubset_2205009Parser::RPAREN, 0);
}

std::vector<CSubset_2205009Parser::StatementContext *> CSubset_2205009Parser::Stat_if_elseContext::statement() {
  return getRuleContexts<CSubset_2205009Parser::StatementContext>();
}

CSubset_2205009Parser::StatementContext* CSubset_2205009Parser::Stat_if_elseContext::statement(size_t i) {
  return getRuleContext<CSubset_2205009Parser::StatementContext>(i);
}

tree::TerminalNode* CSubset_2205009Parser::Stat_if_elseContext::ELSE() {
  return getToken(CSubset_2205009Parser::ELSE, 0);
}

CSubset_2205009Parser::Stat_if_elseContext::Stat_if_elseContext(StatementContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Stat_if_elseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitStat_if_else(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Stat_exprContext ------------------------------------------------------------------

CSubset_2205009Parser::Expression_statementContext* CSubset_2205009Parser::Stat_exprContext::expression_statement() {
  return getRuleContext<CSubset_2205009Parser::Expression_statementContext>(0);
}

CSubset_2205009Parser::Stat_exprContext::Stat_exprContext(StatementContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Stat_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitStat_expr(this);
  else
    return visitor->visitChildren(this);
}
CSubset_2205009Parser::StatementContext* CSubset_2205009Parser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 22, CSubset_2205009Parser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(208);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubset_2205009Parser::Stat_var_decContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(168);
      var_declaration();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubset_2205009Parser::Stat_exprContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(169);
      expression_statement();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CSubset_2205009Parser::Stat_compoundContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(170);
      compound_statement();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<CSubset_2205009Parser::Stat_for_loopContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(171);
      match(CSubset_2205009Parser::FOR);
      setState(172);
      match(CSubset_2205009Parser::LPAREN);
      setState(173);
      expression_statement();
      setState(174);
      expression_statement();
      setState(175);
      expression();
      setState(176);
      match(CSubset_2205009Parser::RPAREN);
      setState(177);
      statement();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<CSubset_2205009Parser::Stat_ifContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(179);
      match(CSubset_2205009Parser::IF);
      setState(180);
      match(CSubset_2205009Parser::LPAREN);
      setState(181);
      expression();
      setState(182);
      match(CSubset_2205009Parser::RPAREN);
      setState(183);
      statement();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<CSubset_2205009Parser::Stat_if_elseContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(185);
      match(CSubset_2205009Parser::IF);
      setState(186);
      match(CSubset_2205009Parser::LPAREN);
      setState(187);
      expression();
      setState(188);
      match(CSubset_2205009Parser::RPAREN);
      setState(189);
      statement();
      setState(190);
      match(CSubset_2205009Parser::ELSE);
      setState(191);
      statement();
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<CSubset_2205009Parser::Stat_whileContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(193);
      match(CSubset_2205009Parser::WHILE);
      setState(194);
      match(CSubset_2205009Parser::LPAREN);
      setState(195);
      expression();
      setState(196);
      match(CSubset_2205009Parser::RPAREN);
      setState(197);
      statement();
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<CSubset_2205009Parser::Stat_printlnContext>(_localctx);
      enterOuterAlt(_localctx, 8);
      setState(199);
      match(CSubset_2205009Parser::PRINTLN);
      setState(200);
      match(CSubset_2205009Parser::LPAREN);
      setState(201);
      match(CSubset_2205009Parser::ID);
      setState(202);
      match(CSubset_2205009Parser::RPAREN);
      setState(203);
      match(CSubset_2205009Parser::SEMICOLON);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<CSubset_2205009Parser::Stat_returnContext>(_localctx);
      enterOuterAlt(_localctx, 9);
      setState(204);
      match(CSubset_2205009Parser::RETURN);
      setState(205);
      expression();
      setState(206);
      match(CSubset_2205009Parser::SEMICOLON);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_statementContext ------------------------------------------------------------------

CSubset_2205009Parser::Expression_statementContext::Expression_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubset_2205009Parser::Expression_statementContext::getRuleIndex() const {
  return CSubset_2205009Parser::RuleExpression_statement;
}

void CSubset_2205009Parser::Expression_statementContext::copyFrom(Expression_statementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Expr_endContext ------------------------------------------------------------------

tree::TerminalNode* CSubset_2205009Parser::Expr_endContext::SEMICOLON() {
  return getToken(CSubset_2205009Parser::SEMICOLON, 0);
}

CSubset_2205009Parser::Expr_endContext::Expr_endContext(Expression_statementContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Expr_endContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitExpr_end(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Expr_assign_addopContext ------------------------------------------------------------------

std::vector<CSubset_2205009Parser::ExpressionContext *> CSubset_2205009Parser::Expr_assign_addopContext::expression() {
  return getRuleContexts<CSubset_2205009Parser::ExpressionContext>();
}

CSubset_2205009Parser::ExpressionContext* CSubset_2205009Parser::Expr_assign_addopContext::expression(size_t i) {
  return getRuleContext<CSubset_2205009Parser::ExpressionContext>(i);
}

tree::TerminalNode* CSubset_2205009Parser::Expr_assign_addopContext::ADDOP() {
  return getToken(CSubset_2205009Parser::ADDOP, 0);
}

tree::TerminalNode* CSubset_2205009Parser::Expr_assign_addopContext::ASSIGNOP() {
  return getToken(CSubset_2205009Parser::ASSIGNOP, 0);
}

CSubset_2205009Parser::Expr_assign_addopContext::Expr_assign_addopContext(Expression_statementContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Expr_assign_addopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitExpr_assign_addop(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Expr_with_exprContext ------------------------------------------------------------------

CSubset_2205009Parser::ExpressionContext* CSubset_2205009Parser::Expr_with_exprContext::expression() {
  return getRuleContext<CSubset_2205009Parser::ExpressionContext>(0);
}

tree::TerminalNode* CSubset_2205009Parser::Expr_with_exprContext::SEMICOLON() {
  return getToken(CSubset_2205009Parser::SEMICOLON, 0);
}

CSubset_2205009Parser::Expr_with_exprContext::Expr_with_exprContext(Expression_statementContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Expr_with_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitExpr_with_expr(this);
  else
    return visitor->visitChildren(this);
}
CSubset_2205009Parser::Expression_statementContext* CSubset_2205009Parser::expression_statement() {
  Expression_statementContext *_localctx = _tracker.createInstance<Expression_statementContext>(_ctx, getState());
  enterRule(_localctx, 24, CSubset_2205009Parser::RuleExpression_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(219);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubset_2205009Parser::Expr_endContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(210);
      match(CSubset_2205009Parser::SEMICOLON);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubset_2205009Parser::Expr_with_exprContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(211);
      expression();
      setState(212);
      match(CSubset_2205009Parser::SEMICOLON);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CSubset_2205009Parser::Expr_assign_addopContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(214);
      expression();
      setState(215);
      match(CSubset_2205009Parser::ADDOP);
      setState(216);
      match(CSubset_2205009Parser::ASSIGNOP);
      setState(217);
      expression();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

CSubset_2205009Parser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubset_2205009Parser::VariableContext::getRuleIndex() const {
  return CSubset_2205009Parser::RuleVariable;
}

void CSubset_2205009Parser::VariableContext::copyFrom(VariableContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Var_arrContext ------------------------------------------------------------------

tree::TerminalNode* CSubset_2205009Parser::Var_arrContext::ID() {
  return getToken(CSubset_2205009Parser::ID, 0);
}

tree::TerminalNode* CSubset_2205009Parser::Var_arrContext::LTHIRD() {
  return getToken(CSubset_2205009Parser::LTHIRD, 0);
}

CSubset_2205009Parser::ExpressionContext* CSubset_2205009Parser::Var_arrContext::expression() {
  return getRuleContext<CSubset_2205009Parser::ExpressionContext>(0);
}

tree::TerminalNode* CSubset_2205009Parser::Var_arrContext::RTHIRD() {
  return getToken(CSubset_2205009Parser::RTHIRD, 0);
}

CSubset_2205009Parser::Var_arrContext::Var_arrContext(VariableContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Var_arrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitVar_arr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Var_idContext ------------------------------------------------------------------

tree::TerminalNode* CSubset_2205009Parser::Var_idContext::ID() {
  return getToken(CSubset_2205009Parser::ID, 0);
}

CSubset_2205009Parser::Var_idContext::Var_idContext(VariableContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Var_idContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitVar_id(this);
  else
    return visitor->visitChildren(this);
}
CSubset_2205009Parser::VariableContext* CSubset_2205009Parser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 26, CSubset_2205009Parser::RuleVariable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(227);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubset_2205009Parser::Var_idContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(221);
      match(CSubset_2205009Parser::ID);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubset_2205009Parser::Var_arrContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(222);
      match(CSubset_2205009Parser::ID);
      setState(223);
      match(CSubset_2205009Parser::LTHIRD);
      setState(224);
      expression();
      setState(225);
      match(CSubset_2205009Parser::RTHIRD);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

CSubset_2205009Parser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubset_2205009Parser::ExpressionContext::getRuleIndex() const {
  return CSubset_2205009Parser::RuleExpression;
}

void CSubset_2205009Parser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Expr_assignContext ------------------------------------------------------------------

CSubset_2205009Parser::VariableContext* CSubset_2205009Parser::Expr_assignContext::variable() {
  return getRuleContext<CSubset_2205009Parser::VariableContext>(0);
}

tree::TerminalNode* CSubset_2205009Parser::Expr_assignContext::ASSIGNOP() {
  return getToken(CSubset_2205009Parser::ASSIGNOP, 0);
}

CSubset_2205009Parser::Logic_expressionContext* CSubset_2205009Parser::Expr_assignContext::logic_expression() {
  return getRuleContext<CSubset_2205009Parser::Logic_expressionContext>(0);
}

CSubset_2205009Parser::Expr_assignContext::Expr_assignContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Expr_assignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitExpr_assign(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Expr_logicContext ------------------------------------------------------------------

CSubset_2205009Parser::Logic_expressionContext* CSubset_2205009Parser::Expr_logicContext::logic_expression() {
  return getRuleContext<CSubset_2205009Parser::Logic_expressionContext>(0);
}

CSubset_2205009Parser::Expr_logicContext::Expr_logicContext(ExpressionContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Expr_logicContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitExpr_logic(this);
  else
    return visitor->visitChildren(this);
}
CSubset_2205009Parser::ExpressionContext* CSubset_2205009Parser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 28, CSubset_2205009Parser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(234);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubset_2205009Parser::Expr_logicContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(229);
      logic_expression();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubset_2205009Parser::Expr_assignContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(230);
      variable();
      setState(231);
      match(CSubset_2205009Parser::ASSIGNOP);
      setState(232);
      logic_expression();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Logic_expressionContext ------------------------------------------------------------------

CSubset_2205009Parser::Logic_expressionContext::Logic_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubset_2205009Parser::Logic_expressionContext::getRuleIndex() const {
  return CSubset_2205009Parser::RuleLogic_expression;
}

void CSubset_2205009Parser::Logic_expressionContext::copyFrom(Logic_expressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Logic_relContext ------------------------------------------------------------------

CSubset_2205009Parser::Rel_expressionContext* CSubset_2205009Parser::Logic_relContext::rel_expression() {
  return getRuleContext<CSubset_2205009Parser::Rel_expressionContext>(0);
}

CSubset_2205009Parser::Logic_relContext::Logic_relContext(Logic_expressionContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Logic_relContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitLogic_rel(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Logic_opContext ------------------------------------------------------------------

std::vector<CSubset_2205009Parser::Rel_expressionContext *> CSubset_2205009Parser::Logic_opContext::rel_expression() {
  return getRuleContexts<CSubset_2205009Parser::Rel_expressionContext>();
}

CSubset_2205009Parser::Rel_expressionContext* CSubset_2205009Parser::Logic_opContext::rel_expression(size_t i) {
  return getRuleContext<CSubset_2205009Parser::Rel_expressionContext>(i);
}

tree::TerminalNode* CSubset_2205009Parser::Logic_opContext::LOGICOP() {
  return getToken(CSubset_2205009Parser::LOGICOP, 0);
}

CSubset_2205009Parser::Logic_opContext::Logic_opContext(Logic_expressionContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Logic_opContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitLogic_op(this);
  else
    return visitor->visitChildren(this);
}
CSubset_2205009Parser::Logic_expressionContext* CSubset_2205009Parser::logic_expression() {
  Logic_expressionContext *_localctx = _tracker.createInstance<Logic_expressionContext>(_ctx, getState());
  enterRule(_localctx, 30, CSubset_2205009Parser::RuleLogic_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(241);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubset_2205009Parser::Logic_relContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(236);
      rel_expression();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubset_2205009Parser::Logic_opContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(237);
      rel_expression();
      setState(238);
      match(CSubset_2205009Parser::LOGICOP);
      setState(239);
      rel_expression();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Rel_expressionContext ------------------------------------------------------------------

CSubset_2205009Parser::Rel_expressionContext::Rel_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubset_2205009Parser::Rel_expressionContext::getRuleIndex() const {
  return CSubset_2205009Parser::RuleRel_expression;
}

void CSubset_2205009Parser::Rel_expressionContext::copyFrom(Rel_expressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Rel_simpleContext ------------------------------------------------------------------

CSubset_2205009Parser::Simple_expressionContext* CSubset_2205009Parser::Rel_simpleContext::simple_expression() {
  return getRuleContext<CSubset_2205009Parser::Simple_expressionContext>(0);
}

CSubset_2205009Parser::Rel_simpleContext::Rel_simpleContext(Rel_expressionContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Rel_simpleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitRel_simple(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Rel_opContext ------------------------------------------------------------------

std::vector<CSubset_2205009Parser::Simple_expressionContext *> CSubset_2205009Parser::Rel_opContext::simple_expression() {
  return getRuleContexts<CSubset_2205009Parser::Simple_expressionContext>();
}

CSubset_2205009Parser::Simple_expressionContext* CSubset_2205009Parser::Rel_opContext::simple_expression(size_t i) {
  return getRuleContext<CSubset_2205009Parser::Simple_expressionContext>(i);
}

tree::TerminalNode* CSubset_2205009Parser::Rel_opContext::RELOP() {
  return getToken(CSubset_2205009Parser::RELOP, 0);
}

CSubset_2205009Parser::Rel_opContext::Rel_opContext(Rel_expressionContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Rel_opContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitRel_op(this);
  else
    return visitor->visitChildren(this);
}
CSubset_2205009Parser::Rel_expressionContext* CSubset_2205009Parser::rel_expression() {
  Rel_expressionContext *_localctx = _tracker.createInstance<Rel_expressionContext>(_ctx, getState());
  enterRule(_localctx, 32, CSubset_2205009Parser::RuleRel_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(248);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubset_2205009Parser::Rel_simpleContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(243);
      simple_expression(0);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubset_2205009Parser::Rel_opContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(244);
      simple_expression(0);
      setState(245);
      match(CSubset_2205009Parser::RELOP);
      setState(246);
      simple_expression(0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_expressionContext ------------------------------------------------------------------

CSubset_2205009Parser::Simple_expressionContext::Simple_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubset_2205009Parser::Simple_expressionContext::getRuleIndex() const {
  return CSubset_2205009Parser::RuleSimple_expression;
}

void CSubset_2205009Parser::Simple_expressionContext::copyFrom(Simple_expressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Simp_termContext ------------------------------------------------------------------

CSubset_2205009Parser::TermContext* CSubset_2205009Parser::Simp_termContext::term() {
  return getRuleContext<CSubset_2205009Parser::TermContext>(0);
}

CSubset_2205009Parser::Simp_termContext::Simp_termContext(Simple_expressionContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Simp_termContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitSimp_term(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Simp_addopContext ------------------------------------------------------------------

CSubset_2205009Parser::Simple_expressionContext* CSubset_2205009Parser::Simp_addopContext::simple_expression() {
  return getRuleContext<CSubset_2205009Parser::Simple_expressionContext>(0);
}

tree::TerminalNode* CSubset_2205009Parser::Simp_addopContext::ADDOP() {
  return getToken(CSubset_2205009Parser::ADDOP, 0);
}

CSubset_2205009Parser::TermContext* CSubset_2205009Parser::Simp_addopContext::term() {
  return getRuleContext<CSubset_2205009Parser::TermContext>(0);
}

CSubset_2205009Parser::Simp_addopContext::Simp_addopContext(Simple_expressionContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Simp_addopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitSimp_addop(this);
  else
    return visitor->visitChildren(this);
}

CSubset_2205009Parser::Simple_expressionContext* CSubset_2205009Parser::simple_expression() {
   return simple_expression(0);
}

CSubset_2205009Parser::Simple_expressionContext* CSubset_2205009Parser::simple_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubset_2205009Parser::Simple_expressionContext *_localctx = _tracker.createInstance<Simple_expressionContext>(_ctx, parentState);
  CSubset_2205009Parser::Simple_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 34;
  enterRecursionRule(_localctx, 34, CSubset_2205009Parser::RuleSimple_expression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<Simp_termContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(251);
    term(0);
    _ctx->stop = _input->LT(-1);
    setState(258);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<Simp_addopContext>(_tracker.createInstance<Simple_expressionContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleSimple_expression);
        setState(253);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(254);
        match(CSubset_2205009Parser::ADDOP);
        setState(255);
        term(0); 
      }
      setState(260);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

CSubset_2205009Parser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubset_2205009Parser::TermContext::getRuleIndex() const {
  return CSubset_2205009Parser::RuleTerm;
}

void CSubset_2205009Parser::TermContext::copyFrom(TermContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Term_mulopContext ------------------------------------------------------------------

CSubset_2205009Parser::TermContext* CSubset_2205009Parser::Term_mulopContext::term() {
  return getRuleContext<CSubset_2205009Parser::TermContext>(0);
}

tree::TerminalNode* CSubset_2205009Parser::Term_mulopContext::MULOP() {
  return getToken(CSubset_2205009Parser::MULOP, 0);
}

CSubset_2205009Parser::Unary_expressionContext* CSubset_2205009Parser::Term_mulopContext::unary_expression() {
  return getRuleContext<CSubset_2205009Parser::Unary_expressionContext>(0);
}

CSubset_2205009Parser::Term_mulopContext::Term_mulopContext(TermContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Term_mulopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitTerm_mulop(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Term_unaryContext ------------------------------------------------------------------

CSubset_2205009Parser::Unary_expressionContext* CSubset_2205009Parser::Term_unaryContext::unary_expression() {
  return getRuleContext<CSubset_2205009Parser::Unary_expressionContext>(0);
}

CSubset_2205009Parser::Term_unaryContext::Term_unaryContext(TermContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Term_unaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitTerm_unary(this);
  else
    return visitor->visitChildren(this);
}

CSubset_2205009Parser::TermContext* CSubset_2205009Parser::term() {
   return term(0);
}

CSubset_2205009Parser::TermContext* CSubset_2205009Parser::term(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubset_2205009Parser::TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, parentState);
  CSubset_2205009Parser::TermContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 36;
  enterRecursionRule(_localctx, 36, CSubset_2205009Parser::RuleTerm, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<Term_unaryContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(262);
    unary_expression();
    _ctx->stop = _input->LT(-1);
    setState(269);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<Term_mulopContext>(_tracker.createInstance<TermContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleTerm);
        setState(264);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(265);
        match(CSubset_2205009Parser::MULOP);
        setState(266);
        unary_expression(); 
      }
      setState(271);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Unary_expressionContext ------------------------------------------------------------------

CSubset_2205009Parser::Unary_expressionContext::Unary_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubset_2205009Parser::Unary_expressionContext::getRuleIndex() const {
  return CSubset_2205009Parser::RuleUnary_expression;
}

void CSubset_2205009Parser::Unary_expressionContext::copyFrom(Unary_expressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Unary_notContext ------------------------------------------------------------------

tree::TerminalNode* CSubset_2205009Parser::Unary_notContext::NOT() {
  return getToken(CSubset_2205009Parser::NOT, 0);
}

CSubset_2205009Parser::Unary_expressionContext* CSubset_2205009Parser::Unary_notContext::unary_expression() {
  return getRuleContext<CSubset_2205009Parser::Unary_expressionContext>(0);
}

CSubset_2205009Parser::Unary_notContext::Unary_notContext(Unary_expressionContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Unary_notContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitUnary_not(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Unary_factorContext ------------------------------------------------------------------

CSubset_2205009Parser::FactorContext* CSubset_2205009Parser::Unary_factorContext::factor() {
  return getRuleContext<CSubset_2205009Parser::FactorContext>(0);
}

CSubset_2205009Parser::Unary_factorContext::Unary_factorContext(Unary_expressionContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Unary_factorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitUnary_factor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Unary_addopContext ------------------------------------------------------------------

tree::TerminalNode* CSubset_2205009Parser::Unary_addopContext::ADDOP() {
  return getToken(CSubset_2205009Parser::ADDOP, 0);
}

CSubset_2205009Parser::Unary_expressionContext* CSubset_2205009Parser::Unary_addopContext::unary_expression() {
  return getRuleContext<CSubset_2205009Parser::Unary_expressionContext>(0);
}

CSubset_2205009Parser::Unary_addopContext::Unary_addopContext(Unary_expressionContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Unary_addopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitUnary_addop(this);
  else
    return visitor->visitChildren(this);
}
CSubset_2205009Parser::Unary_expressionContext* CSubset_2205009Parser::unary_expression() {
  Unary_expressionContext *_localctx = _tracker.createInstance<Unary_expressionContext>(_ctx, getState());
  enterRule(_localctx, 38, CSubset_2205009Parser::RuleUnary_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(277);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CSubset_2205009Parser::ADDOP: {
        _localctx = _tracker.createInstance<CSubset_2205009Parser::Unary_addopContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(272);
        match(CSubset_2205009Parser::ADDOP);
        setState(273);
        unary_expression();
        break;
      }

      case CSubset_2205009Parser::NOT: {
        _localctx = _tracker.createInstance<CSubset_2205009Parser::Unary_notContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(274);
        match(CSubset_2205009Parser::NOT);
        setState(275);
        unary_expression();
        break;
      }

      case CSubset_2205009Parser::LPAREN:
      case CSubset_2205009Parser::ID:
      case CSubset_2205009Parser::CONST_INT:
      case CSubset_2205009Parser::CONST_FLOAT: {
        _localctx = _tracker.createInstance<CSubset_2205009Parser::Unary_factorContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(276);
        factor();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

CSubset_2205009Parser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubset_2205009Parser::FactorContext::getRuleIndex() const {
  return CSubset_2205009Parser::RuleFactor;
}

void CSubset_2205009Parser::FactorContext::copyFrom(FactorContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Factor_func_callContext ------------------------------------------------------------------

tree::TerminalNode* CSubset_2205009Parser::Factor_func_callContext::ID() {
  return getToken(CSubset_2205009Parser::ID, 0);
}

tree::TerminalNode* CSubset_2205009Parser::Factor_func_callContext::LPAREN() {
  return getToken(CSubset_2205009Parser::LPAREN, 0);
}

CSubset_2205009Parser::Argument_listContext* CSubset_2205009Parser::Factor_func_callContext::argument_list() {
  return getRuleContext<CSubset_2205009Parser::Argument_listContext>(0);
}

tree::TerminalNode* CSubset_2205009Parser::Factor_func_callContext::RPAREN() {
  return getToken(CSubset_2205009Parser::RPAREN, 0);
}

CSubset_2205009Parser::Factor_func_callContext::Factor_func_callContext(FactorContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Factor_func_callContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitFactor_func_call(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Factor_varContext ------------------------------------------------------------------

CSubset_2205009Parser::VariableContext* CSubset_2205009Parser::Factor_varContext::variable() {
  return getRuleContext<CSubset_2205009Parser::VariableContext>(0);
}

CSubset_2205009Parser::Factor_varContext::Factor_varContext(FactorContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Factor_varContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitFactor_var(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Factor_floatContext ------------------------------------------------------------------

tree::TerminalNode* CSubset_2205009Parser::Factor_floatContext::CONST_FLOAT() {
  return getToken(CSubset_2205009Parser::CONST_FLOAT, 0);
}

CSubset_2205009Parser::Factor_floatContext::Factor_floatContext(FactorContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Factor_floatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitFactor_float(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Factor_decContext ------------------------------------------------------------------

CSubset_2205009Parser::VariableContext* CSubset_2205009Parser::Factor_decContext::variable() {
  return getRuleContext<CSubset_2205009Parser::VariableContext>(0);
}

tree::TerminalNode* CSubset_2205009Parser::Factor_decContext::DECOP() {
  return getToken(CSubset_2205009Parser::DECOP, 0);
}

CSubset_2205009Parser::Factor_decContext::Factor_decContext(FactorContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Factor_decContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitFactor_dec(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Factor_intContext ------------------------------------------------------------------

tree::TerminalNode* CSubset_2205009Parser::Factor_intContext::CONST_INT() {
  return getToken(CSubset_2205009Parser::CONST_INT, 0);
}

CSubset_2205009Parser::Factor_intContext::Factor_intContext(FactorContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Factor_intContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitFactor_int(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Factor_incContext ------------------------------------------------------------------

CSubset_2205009Parser::VariableContext* CSubset_2205009Parser::Factor_incContext::variable() {
  return getRuleContext<CSubset_2205009Parser::VariableContext>(0);
}

tree::TerminalNode* CSubset_2205009Parser::Factor_incContext::INCOP() {
  return getToken(CSubset_2205009Parser::INCOP, 0);
}

CSubset_2205009Parser::Factor_incContext::Factor_incContext(FactorContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Factor_incContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitFactor_inc(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Factor_parenContext ------------------------------------------------------------------

tree::TerminalNode* CSubset_2205009Parser::Factor_parenContext::LPAREN() {
  return getToken(CSubset_2205009Parser::LPAREN, 0);
}

CSubset_2205009Parser::ExpressionContext* CSubset_2205009Parser::Factor_parenContext::expression() {
  return getRuleContext<CSubset_2205009Parser::ExpressionContext>(0);
}

tree::TerminalNode* CSubset_2205009Parser::Factor_parenContext::RPAREN() {
  return getToken(CSubset_2205009Parser::RPAREN, 0);
}

CSubset_2205009Parser::Factor_parenContext::Factor_parenContext(FactorContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Factor_parenContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitFactor_paren(this);
  else
    return visitor->visitChildren(this);
}
CSubset_2205009Parser::FactorContext* CSubset_2205009Parser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 40, CSubset_2205009Parser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(297);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CSubset_2205009Parser::Factor_varContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(279);
      variable();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CSubset_2205009Parser::Factor_func_callContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(280);
      match(CSubset_2205009Parser::ID);
      setState(281);
      match(CSubset_2205009Parser::LPAREN);
      setState(282);
      argument_list();
      setState(283);
      match(CSubset_2205009Parser::RPAREN);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CSubset_2205009Parser::Factor_parenContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(285);
      match(CSubset_2205009Parser::LPAREN);
      setState(286);
      expression();
      setState(287);
      match(CSubset_2205009Parser::RPAREN);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<CSubset_2205009Parser::Factor_intContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(289);
      match(CSubset_2205009Parser::CONST_INT);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<CSubset_2205009Parser::Factor_floatContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(290);
      match(CSubset_2205009Parser::CONST_FLOAT);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<CSubset_2205009Parser::Factor_incContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(291);
      variable();
      setState(292);
      match(CSubset_2205009Parser::INCOP);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<CSubset_2205009Parser::Factor_decContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(294);
      variable();
      setState(295);
      match(CSubset_2205009Parser::DECOP);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Argument_listContext ------------------------------------------------------------------

CSubset_2205009Parser::Argument_listContext::Argument_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubset_2205009Parser::Argument_listContext::getRuleIndex() const {
  return CSubset_2205009Parser::RuleArgument_list;
}

void CSubset_2205009Parser::Argument_listContext::copyFrom(Argument_listContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Arg_list_emptyContext ------------------------------------------------------------------

CSubset_2205009Parser::Arg_list_emptyContext::Arg_list_emptyContext(Argument_listContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Arg_list_emptyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitArg_list_empty(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Arg_listContext ------------------------------------------------------------------

CSubset_2205009Parser::ArgumentsContext* CSubset_2205009Parser::Arg_listContext::arguments() {
  return getRuleContext<CSubset_2205009Parser::ArgumentsContext>(0);
}

CSubset_2205009Parser::Arg_listContext::Arg_listContext(Argument_listContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Arg_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitArg_list(this);
  else
    return visitor->visitChildren(this);
}
CSubset_2205009Parser::Argument_listContext* CSubset_2205009Parser::argument_list() {
  Argument_listContext *_localctx = _tracker.createInstance<Argument_listContext>(_ctx, getState());
  enterRule(_localctx, 42, CSubset_2205009Parser::RuleArgument_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(301);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CSubset_2205009Parser::LPAREN:
      case CSubset_2205009Parser::ADDOP:
      case CSubset_2205009Parser::NOT:
      case CSubset_2205009Parser::ID:
      case CSubset_2205009Parser::CONST_INT:
      case CSubset_2205009Parser::CONST_FLOAT: {
        _localctx = _tracker.createInstance<CSubset_2205009Parser::Arg_listContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(299);
        arguments(0);
        break;
      }

      case CSubset_2205009Parser::RPAREN: {
        _localctx = _tracker.createInstance<CSubset_2205009Parser::Arg_list_emptyContext>(_localctx);
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentsContext ------------------------------------------------------------------

CSubset_2205009Parser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CSubset_2205009Parser::ArgumentsContext::getRuleIndex() const {
  return CSubset_2205009Parser::RuleArguments;
}

void CSubset_2205009Parser::ArgumentsContext::copyFrom(ArgumentsContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Args_multiContext ------------------------------------------------------------------

CSubset_2205009Parser::ArgumentsContext* CSubset_2205009Parser::Args_multiContext::arguments() {
  return getRuleContext<CSubset_2205009Parser::ArgumentsContext>(0);
}

tree::TerminalNode* CSubset_2205009Parser::Args_multiContext::COMMA() {
  return getToken(CSubset_2205009Parser::COMMA, 0);
}

CSubset_2205009Parser::Logic_expressionContext* CSubset_2205009Parser::Args_multiContext::logic_expression() {
  return getRuleContext<CSubset_2205009Parser::Logic_expressionContext>(0);
}

CSubset_2205009Parser::Args_multiContext::Args_multiContext(ArgumentsContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Args_multiContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitArgs_multi(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Args_singleContext ------------------------------------------------------------------

CSubset_2205009Parser::Logic_expressionContext* CSubset_2205009Parser::Args_singleContext::logic_expression() {
  return getRuleContext<CSubset_2205009Parser::Logic_expressionContext>(0);
}

CSubset_2205009Parser::Args_singleContext::Args_singleContext(ArgumentsContext *ctx) { copyFrom(ctx); }


std::any CSubset_2205009Parser::Args_singleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CSubset_2205009Visitor*>(visitor))
    return parserVisitor->visitArgs_single(this);
  else
    return visitor->visitChildren(this);
}

CSubset_2205009Parser::ArgumentsContext* CSubset_2205009Parser::arguments() {
   return arguments(0);
}

CSubset_2205009Parser::ArgumentsContext* CSubset_2205009Parser::arguments(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CSubset_2205009Parser::ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, parentState);
  CSubset_2205009Parser::ArgumentsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 44;
  enterRecursionRule(_localctx, 44, CSubset_2205009Parser::RuleArguments, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<Args_singleContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(304);
    logic_expression();
    _ctx->stop = _input->LT(-1);
    setState(311);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<Args_multiContext>(_tracker.createInstance<ArgumentsContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleArguments);
        setState(306);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(307);
        match(CSubset_2205009Parser::COMMA);
        setState(308);
        logic_expression(); 
      }
      setState(313);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool CSubset_2205009Parser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return programSempred(antlrcpp::downCast<ProgramContext *>(context), predicateIndex);
    case 5: return parameter_listSempred(antlrcpp::downCast<Parameter_listContext *>(context), predicateIndex);
    case 9: return declaration_listSempred(antlrcpp::downCast<Declaration_listContext *>(context), predicateIndex);
    case 10: return statementsSempred(antlrcpp::downCast<StatementsContext *>(context), predicateIndex);
    case 17: return simple_expressionSempred(antlrcpp::downCast<Simple_expressionContext *>(context), predicateIndex);
    case 18: return termSempred(antlrcpp::downCast<TermContext *>(context), predicateIndex);
    case 22: return argumentsSempred(antlrcpp::downCast<ArgumentsContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool CSubset_2205009Parser::programSempred(ProgramContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool CSubset_2205009Parser::parameter_listSempred(Parameter_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 5);
    case 2: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

bool CSubset_2205009Parser::declaration_listSempred(Declaration_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 5);
    case 4: return precpred(_ctx, 4);
    case 5: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CSubset_2205009Parser::statementsSempred(StatementsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 6: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CSubset_2205009Parser::simple_expressionSempred(Simple_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 7: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CSubset_2205009Parser::termSempred(TermContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 8: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CSubset_2205009Parser::argumentsSempred(ArgumentsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 9: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void CSubset_2205009Parser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  csubset_2205009ParserInitialize();
#else
  ::antlr4::internal::call_once(csubset_2205009ParserOnceFlag, csubset_2205009ParserInitialize);
#endif
}
