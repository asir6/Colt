//
//  Copyright (C) 1996-2011 by Autodesk, Inc.
//
//  By using this code, you are agreeing to the terms and conditions of
//  the License Agreement included in the documentation for this code.
//
//  AUTODESK MAKES NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
//  OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT. AUTODESK
//  PROVIDES THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
//  LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
//  OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//  Use, duplication, or disclosure by the U.S. Government is subject to
//  restrictions set forth in FAR 52.227-19 (Commercial Computer Software
//  Restricted Rights) and DFAR 252.227-7013(c)(1)(ii) (Rights in Technical
//  Data and Computer Software), as applicable.
//


// Note: any new strings must be added to the beginning of this preload data
// so that we can continue to read older files (compression offsets are relative
// to the end of the history buffer.

#define WHIP_40_PRELOAD_ADDITIONS   "(DashPattern " \
                                    "(LineStyle "   \
                                    "(Copyright "   \
                                    "(Keywords "    \
                                    "(Viewport "    \
                                    "(CodePage "

extern WT_Byte const WD_History_Buffer_Preload[] =
WHIP_40_PRELOAD_ADDITIONS
// Heidi's color map
"{\x04\x04\x00\x00\x01\x00\x00" // Colormap opcode.
"\x0\x0\x0\xFF\x0\x0\x80\xFF\x0\x80\x0\xFF\x0\x80\x80\xFF"
"\x80\x0\x0\xFF\x80\x0\x80\xFF\x80\x80\x0\xFF\xC0\xC0\xC0\xFF"
"\xC0\xDC\xC0\xFF\xF0\xCA\xA6\xFF\x0\x0\x0\xFF\x33\x0\x0\xFF"
"\x66\x0\x0\xFF\x99\x0\x0\xFF\xCC\x0\x0\xFF\xFF\x0\x0\xFF"
"\x0\x33\x0\xFF\x33\x33\x0\xFF\x66\x33\x0\xFF\x99\x33\x0\xFF"
"\xCC\x33\x0\xFF\xFF\x33\x0\xFF\x0\x66\x0\xFF\x33\x66\x0\xFF"
"\x66\x66\x0\xFF\x99\x66\x0\xFF\xCC\x66\x0\xFF\xFF\x66\x0\xFF"
"\x0\x99\x0\xFF\x33\x99\x0\xFF\x66\x99\x0\xFF\x99\x99\x0\xFF"
"\xCC\x99\x0\xFF\xFF\x99\x0\xFF\x0\xCC\x0\xFF\x33\xCC\x0\xFF"
"\x66\xCC\x0\xFF\x99\xCC\x0\xFF\xCC\xCC\x0\xFF\xFF\xCC\x0\xFF"
"\x0\xFF\x0\xFF\x33\xFF\x0\xFF\x66\xFF\x0\xFF\x99\xFF\x0\xFF"
"\xCC\xFF\x0\xFF\xFF\xFF\x0\xFF\x0\x0\x33\xFF\x33\x0\x33\xFF"
"\x66\x0\x33\xFF\x99\x0\x33\xFF\xCC\x0\x33\xFF\xFF\x0\x33\xFF"
"\x0\x33\x33\xFF\x33\x33\x33\xFF\x66\x33\x33\xFF\x99\x33\x33\xFF"
"\xCC\x33\x33\xFF\xFF\x33\x33\xFF\x0\x66\x33\xFF\x33\x66\x33\xFF"
"\x66\x66\x33\xFF\x99\x66\x33\xFF\xCC\x66\x33\xFF\xFF\x66\x33\xFF"
"\x0\x99\x33\xFF\x33\x99\x33\xFF\x66\x99\x33\xFF\x99\x99\x33\xFF"
"\xCC\x99\x33\xFF\xFF\x99\x33\xFF\x0\xCC\x33\xFF\x33\xCC\x33\xFF"
"\x66\xCC\x33\xFF\x99\xCC\x33\xFF\xCC\xCC\x33\xFF\xFF\xCC\x33\xFF"
"\x0\xFF\x33\xFF\x33\xFF\x33\xFF\x66\xFF\x33\xFF\x99\xFF\x33\xFF"
"\xCC\xFF\x33\xFF\xFF\xFF\x33\xFF\x0\x0\x66\xFF\x33\x0\x66\xFF"
"\x66\x0\x66\xFF\x99\x0\x66\xFF\xCC\x0\x66\xFF\xFF\x0\x66\xFF"
"\x0\x33\x66\xFF\x33\x33\x66\xFF\x66\x33\x66\xFF\x99\x33\x66\xFF"
"\xCC\x33\x66\xFF\xFF\x33\x66\xFF\x0\x66\x66\xFF\x33\x66\x66\xFF"
"\x66\x66\x66\xFF\x99\x66\x66\xFF\xCC\x66\x66\xFF\xFF\x66\x66\xFF"
"\x0\x99\x66\xFF\x33\x99\x66\xFF\x66\x99\x66\xFF\x99\x99\x66\xFF"
"\xCC\x99\x66\xFF\xFF\x99\x66\xFF\x0\xCC\x66\xFF\x33\xCC\x66\xFF"
"\x66\xCC\x66\xFF\x99\xCC\x66\xFF\xCC\xCC\x66\xFF\xFF\xCC\x66\xFF"
"\x0\xFF\x66\xFF\x33\xFF\x66\xFF\x66\xFF\x66\xFF\x99\xFF\x66\xFF"
"\xCC\xFF\x66\xFF\xFF\xFF\x66\xFF\x0\x0\x99\xFF\x33\x0\x99\xFF"
"\x66\x0\x99\xFF\x99\x0\x99\xFF\xCC\x0\x99\xFF\xFF\x0\x99\xFF"
"\x0\x33\x99\xFF\x33\x33\x99\xFF\x66\x33\x99\xFF\x99\x33\x99\xFF"
"\xCC\x33\x99\xFF\xFF\x33\x99\xFF\x0\x66\x99\xFF\x33\x66\x99\xFF"
"\x66\x66\x99\xFF\x99\x66\x99\xFF\xCC\x66\x99\xFF\xFF\x66\x99\xFF"
"\x0\x99\x99\xFF\x33\x99\x99\xFF\x66\x99\x99\xFF\x99\x99\x99\xFF"
"\xCC\x99\x99\xFF\xFF\x99\x99\xFF\x0\xCC\x99\xFF\x33\xCC\x99\xFF"
"\x66\xCC\x99\xFF\x99\xCC\x99\xFF\xCC\xCC\x99\xFF\xFF\xCC\x99\xFF"
"\x0\xFF\x99\xFF\x33\xFF\x99\xFF\x66\xFF\x99\xFF\x99\xFF\x99\xFF"
"\xCC\xFF\x99\xFF\xFF\xFF\x99\xFF\x0\x0\xCC\xFF\x33\x0\xCC\xFF"
"\x66\x0\xCC\xFF\x99\x0\xCC\xFF\xCC\x0\xCC\xFF\xFF\x0\xCC\xFF"
"\x0\x33\xCC\xFF\x33\x33\xCC\xFF\x66\x33\xCC\xFF\x99\x33\xCC\xFF"
"\xCC\x33\xCC\xFF\xFF\x33\xCC\xFF\x0\x66\xCC\xFF\x33\x66\xCC\xFF"
"\x66\x66\xCC\xFF\x99\x66\xCC\xFF\xCC\x66\xCC\xFF\xFF\x66\xCC\xFF"
"\x0\x99\xCC\xFF\x33\x99\xCC\xFF\x66\x99\xCC\xFF\x99\x99\xCC\xFF"
"\xCC\x99\xCC\xFF\xFF\x99\xCC\xFF\x0\xCC\xCC\xFF\x33\xCC\xCC\xFF"
"\x66\xCC\xCC\xFF\x99\xCC\xCC\xFF\xCC\xCC\xCC\xFF\xFF\xCC\xCC\xFF"
"\x0\xFF\xCC\xFF\x33\xFF\xCC\xFF\x66\xFF\xCC\xFF\x99\xFF\xCC\xFF"
"\xCC\xFF\xCC\xFF\xFF\xFF\xCC\xFF\x0\x0\xFF\xFF\x33\x0\xFF\xFF"
"\x66\x0\xFF\xFF\x99\x0\xFF\xFF\xCC\x0\xFF\xFF\xFF\x0\xFF\xFF"
"\x0\x33\xFF\xFF\x33\x33\xFF\xFF\x66\x33\xFF\xFF\x99\x33\xFF\xFF"
"\xCC\x33\xFF\xFF\xFF\x33\xFF\xFF\x0\x66\xFF\xFF\x33\x66\xFF\xFF"
"\x66\x66\xFF\xFF\x99\x66\xFF\xFF\xCC\x66\xFF\xFF\xFF\x66\xFF\xFF"
"\x0\x99\xFF\xFF\x33\x99\xFF\xFF\x66\x99\xFF\xFF\x99\x99\xFF\xFF"
"\xCC\x99\xFF\xFF\xFF\x99\xFF\xFF\x0\xCC\xFF\xFF\x33\xCC\xFF\xFF"
"\x66\xCC\xFF\xFF\x99\xCC\xFF\xFF\xCC\xCC\xFF\xFF\xFF\xCC\xFF\xFF"
"\x0\xFF\xFF\xFF\x33\xFF\xFF\xFF\x66\xFF\xFF\xFF\x99\xFF\xFF\xFF"
"\xCC\xFF\xFF\xFF\xFF\xFF\xFF\xFF\x0\x0\x0\xFF\xD\xD\xD\xFF"
"\x1A\x1A\x1A\xFF\x28\x28\x28\xFF\x35\x35\x35\xFF\x43\x43\x43\xFF"
"\x50\x50\x50\xFF\x5D\x5D\x5D\xFF\x6B\x6B\x6B\xFF\x78\x78\x78\xFF"
"\x86\x86\x86\xFF\x93\x93\x93\xFF\xA1\xA1\xA1\xFF\xAE\xAE\xAE\xFF"
"\xBB\xBB\xBB\xFF\xC9\xC9\xC9\xFF\xD6\xD6\xD6\xFF\xE4\xE4\xE4\xFF"
"\xF1\xF1\xF1\xFF\xFF\xFF\xFF\xFF\xF0\xFB\xFF\xFF\xA4\xA0\xA0\xFF"
"\x80\x80\x80\xFF\x0\x0\xFF\xFF\x0\xFF\x0\xFF\x0\xFF\xFF\xFF"
"\xFF\x0\x0\xFF\xFF\x0\xFF\xFF\xFF\xFF\x0\xFF\xFF\xFF\xFF\xFF"
// The extended ascii opcodes
"(NamedView "
"(Author "
"(Background "
"(Bezier "
"(Bounds "
"(Clip "
"(Color "
"(ColorMap "
"(Comment "
"(Created "
"(Creator "
"(Description "
"(DrawingInfo "
")(Embed 'image/vnd.dwg;' 'AutoCAD-r13' 'unknown.dwg' '')"
"(View "
"(Gouraud "
"(Image "
"(Layer "
"(LineCap "
"(LineJoin "
"(LinePattern "
"(LineWeight "
"(Modified "
"(Projection "
"(Scale "
"(SourceCreated "
"(SourceFilename "
"(SourceModified "
"(Text "
"(URL 'http://www.com')"
"'ftp://ftp."
"00001000200030004000500060007000800090011001200130"  // All possible 4-digit ASCII numbers
"01400150016001700180019002100220023002400250026002"
"70028002900310032003300340035003600370038003900410"
"04200430044004500460047004800490051005200530054005"
"50056005700580059006100620063006400650066006700680"
"06900710072007300740075007600770078007900810082008"
"30084008500860087008800890091009200930094009500960"
"09700980099010102010301040105010601070108010901110"
"11201130114011501160117011801190121012201230124012"
"50126012701280129013101320133013401350136013701380"
"13901410142014301440145014601470148014901510152015"
"30154015501560157015801590161016201630164016501660"
"16701680169017101720173017401750176017701780179018"
"10182018301840185018601870188018901910192019301940"
"19501960197019801990202030204020502060207020802090"
"21102120213021402150216021702180219022102220223022"
"40225022602270228022902310232023302340235023602370"
"23802390241024202430244024502460247024802490251025"
"20253025402550256025702580259026102620263026402650"
"26602670268026902710272027302740275027602770278027"
"90281028202830284028502860287028802890291029202930"
"29402950296029702980299030304030503060307030803090"
"31103120313031403150316031703180319032103220323032"
"40325032603270328032903310332033303340335033603370"
"33803390341034203430344034503460347034803490351035"
"20353035403550356035703580359036103620363036403650"
"36603670368036903710372037303740375037603770378037"
"90381038203830384038503860387038803890391039203930"
"39403950396039703980399040405040604070408040904110"
"41204130414041504160417041804190421042204230424042"
"50426042704280429043104320433043404350436043704380"
"43904410442044304440445044604470448044904510452045"
"30454045504560457045804590461046204630464046504660"
"46704680469047104720473047404750476047704780479048"
"10482048304840485048604870488048904910492049304940"
"49504960497049804990505060507050805090511051205130"
"51405150516051705180519052105220523052405250526052"
"70528052905310532053305340535053605370538053905410"
"54205430544054505460547054805490551055205530554055"
"50556055705580559056105620563056405650566056705680"
"56905710572057305740575057605770578057905810582058"
"30584058505860587058805890591059205930594059505960"
"59705980599060607060806090611061206130614061506160"
"61706180619062106220623062406250626062706280629063"
"10632063306340635063606370638063906410642064306440"
"64506460647064806490651065206530654065506560657065"
"80659066106620663066406650666066706680669067106720"
"67306740675067606770678067906810682068306840685068"
"60687068806890691069206930694069506960697069806990"
"70708070907110712071307140715071607170718071907210"
"72207230724072507260727072807290731073207330734073"
"50736073707380739074107420743074407450746074707480"
"74907510752075307540755075607570758075907610762076"
"30764076507660767076807690771077207730774077507760"
"77707780779078107820783078407850786078707880789079"
"10792079307940795079607970798079908080908110812081"
"30814081508160817081808190821082208230824082508260"
"82708280829083108320833083408350836083708380839084"
"10842084308440845084608470848084908510852085308540"
"85508560857085808590861086208630864086508660867086"
"80869087108720873087408750876087708780879088108820"
"88308840885088608870888088908910892089308940895089"
"60897089808990909110912091309140915091609170918091"
"90921092209230924092509260927092809290931093209330"
"93409350936093709380939094109420943094409450946094"
"70948094909510952095309540955095609570958095909610"
"96209630964096509660967096809690971097209730974097"
"50976097709780979098109820983098409850986098709880"
"98909910992099309940995099609970998099911112111311"
"14111511161117111811191122112311241125112611271128"
"11291132113311341135113611371138113911421143114411"
"45114611471148114911521153115411551156115711581159"
"11621163116411651166116711681169117211731174117511"
"76117711781179118211831184118511861187118811891192"
"11931194119511961197119811991212131214121512161217"
"12181219122212231224122512261227122812291232123312"
"34123512361237123812391242124312441245124612471248"
"12491252125312541255125612571258125912621263126412"
"65126612671268126912721273127412751276127712781279"
"12821283128412851286128712881289129212931294129512"
"96129712981299131314131513161317131813191322132313"
"24132513261327132813291332133313341335133613371338"
"13391342134313441345134613471348134913521353135413"
"55135613571358135913621363136413651366136713681369"
"13721373137413751376137713781379138213831384138513"
"86138713881389139213931394139513961397139813991414"
"15141614171418141914221423142414251426142714281429"
"14321433143414351436143714381439144214431444144514"
"46144714481449145214531454145514561457145814591462"
"14631464146514661467146814691472147314741475147614"
"77147814791482148314841485148614871488148914921493"
"14941495149614971498149915151615171518151915221523"
"15241525152615271528152915321533153415351536153715"
"38153915421543154415451546154715481549155215531554"
"15551556155715581559156215631564156515661567156815"
"69157215731574157515761577157815791582158315841585"
"15861587158815891592159315941595159615971598159916"
"16171618161916221623162416251626162716281629163216"
"33163416351636163716381639164216431644164516461647"
"16481649165216531654165516561657165816591662166316"
"64166516661667166816691672167316741675167616771678"
"16791682168316841685168616871688168916921693169416"
"95169616971698169917171817191722172317241725172617"
"27172817291732173317341735173617371738173917421743"
"17441745174617471748174917521753175417551756175717"
"58175917621763176417651766176717681769177217731774"
"17751776177717781779178217831784178517861787178817"
"89179217931794179517961797179817991818191822182318"
"24182518261827182818291832183318341835183618371838"
"18391842184318441845184618471848184918521853185418"
"55185618571858185918621863186418651866186718681869"
"18721873187418751876187718781879188218831884188518"
"86188718881889189218931894189518961897189818991919"
"22192319241925192619271928192919321933193419351936"
"19371938193919421943194419451946194719481949195219"
"53195419551956195719581959196219631964196519661967"
"19681969197219731974197519761977197819791982198319"
"84198519861987198819891992199319941995199619971998"
"19992222322242225222622272228222922332234223522362"
"23722382239224322442245224622472248224922532254225"
"52256225722582259226322642265226622672268226922732"
"27422752276227722782279228322842285228622872288228"
"92293229422952296229722982299232324232523262327232"
"82329233323342335233623372338233923432344234523462"
"34723482349235323542355235623572358235923632364236"
"52366236723682369237323742375237623772378237923832"
"38423852386238723882389239323942395239623972398239"
"92424252426242724282429243324342435243624372438243"
"92443244424452446244724482449245324542455245624572"
"45824592463246424652466246724682469247324742475247"
"62477247824792483248424852486248724882489249324942"
"49524962497249824992525262527252825292533253425352"
"53625372538253925432544254525462547254825492553255"
"42555255625572558255925632564256525662567256825692"
"57325742575257625772578257925832584258525862587258"
"82589259325942595259625972598259926262726282629263"
"32634263526362637263826392643264426452646264726482"
"64926532654265526562657265826592663266426652666266"
"72668266926732674267526762677267826792683268426852"
"68626872688268926932694269526962697269826992727282"
"72927332734273527362737273827392743274427452746274"
"72748274927532754275527562757275827592763276427652"
"76627672768276927732774277527762777277827792783278"
"42785278627872788278927932794279527962797279827992"
"82829283328342835283628372838283928432844284528462"
"84728482849285328542855285628572858285928632864286"
"52866286728682869287328742875287628772878287928832"
"88428852886288728882889289328942895289628972898289"
"92929332934293529362937293829392943294429452946294"
"72948294929532954295529562957295829592963296429652"
"96629672968296929732974297529762977297829792983298"
"42985298629872988298929932994299529962997299829993"
"33343335333633373338333933443345334633473348334933"
"54335533563357335833593364336533663367336833693374"
"33753376337733783379338433853386338733883389339433"
"95339633973398339934343534363437343834393444344534"
"46344734483449345434553456345734583459346434653466"
"34673468346934743475347634773478347934843485348634"
"87348834893494349534963497349834993535363537353835"
"39354435453546354735483549355435553556355735583559"
"35643565356635673568356935743575357635773578357935"
"84358535863587358835893594359535963597359835993636"
"37363836393644364536463647364836493654365536563657"
"36583659366436653666366736683669367436753676367736"
"78367936843685368636873688368936943695369636973698"
"36993737383739374437453746374737483749375437553756"
"37573758375937643765376637673768376937743775377637"
"77377837793784378537863787378837893794379537963797"
"37983799383839384438453846384738483849385438553856"
"38573858385938643865386638673868386938743875387638"
"77387838793884388538863887388838893894389538963897"
"38983899393944394539463947394839493954395539563957"
"39583959396439653966396739683969397439753976397739"
"78397939843985398639873988398939943995399639973998"
"39994444544464447444844494455445644574458445944654"
"46644674468446944754476447744784479448544864487448"
"84489449544964497449844994545464547454845494555455"
"64557455845594565456645674568456945754576457745784"
"57945854586458745884589459545964597459845994646474"
"64846494655465646574658465946654666466746684669467"
"54676467746784679468546864687468846894695469646974"
"69846994747484749475547564757475847594765476647674"
"76847694775477647774778477947854786478747884789479"
"54796479747984799484849485548564857485848594865486"
"64867486848694875487648774878487948854886488748884"
"88948954896489748984899494955495649574958495949654"
"96649674968496949754976497749784979498549864987498"
"84989499549964997499849995555655575558555955665567"
"55685569557655775578557955865587558855895596559755"
"98559956565756585659566656675668566956765677567856"
"79568656875688568956965697569856995757585759576657"
"67576857695776577757785779578657875788578957965797"
"57985799585859586658675868586958765877587858795886"
"58875888588958965897589858995959665967596859695976"
"59775978597959865987598859895996599759985999666676"
"66866696677667866796687668866896697669866996767686"
"76967776778677967876788678967976798679968686968776"
"87868796887688868896897689868996969776978697969876"
"98869896997699869997777877797788778977987799787879"
"78887889789878997979887989799879998888988998989999"
"000"
"{\x04\x04\x00\x00\x01\x00\x00" // Colormap opcode.
// Default Acad "White" R13c4 Palette
"\xFF\xFF\xFF\xFF\x0\x0\xFF\xFF\x0\xFF\xFF\xFF\x0\xFF\x0\xFF"
"\xFF\xFF\x0\xFF\xFF\x0\x0\xFF\xFF\x0\xFF\xFF\x0\x0\x0\xFF"
"\x80\x80\x80\xFF\xC0\xC0\xC0\xFF\x0\x0\xFF\xFF\x7F\x7F\xFF\xFF"
"\x0\x0\xA5\xFF\x52\x52\xA5\xFF\x0\x0\x7F\xFF\x3F\x3F\x7F\xFF"
"\x0\x0\x4C\xFF\x26\x26\x4C\xFF\x0\x0\x26\xFF\x13\x13\x26\xFF"
"\x0\x3F\xFF\xFF\x7F\x9F\xFF\xFF\x0\x29\xA5\xFF\x52\x67\xA5\xFF"
"\x0\x1F\x7F\xFF\x3F\x4F\x7F\xFF\x0\x13\x4C\xFF\x26\x2F\x4C\xFF"
"\x0\x9\x26\xFF\x13\x17\x26\xFF\x0\x7F\xFF\xFF\x7F\xBF\xFF\xFF"
"\x0\x52\xA5\xFF\x52\x7C\xA5\xFF\x0\x3F\x7F\xFF\x3F\x5F\x7F\xFF"
"\x0\x26\x4C\xFF\x26\x39\x4C\xFF\x0\x13\x26\xFF\x13\x1C\x26\xFF"
"\x0\xBF\xFF\xFF\x7F\xDF\xFF\xFF\x0\x7C\xA5\xFF\x52\x91\xA5\xFF"
"\x0\x5F\x7F\xFF\x3F\x6F\x7F\xFF\x0\x39\x4C\xFF\x26\x42\x4C\xFF"
"\x0\x1C\x26\xFF\x13\x21\x26\xFF\x0\xFF\xFF\xFF\x7F\xFF\xFF\xFF"
"\x0\xA5\xA5\xFF\x52\xA5\xA5\xFF\x0\x7F\x7F\xFF\x3F\x7F\x7F\xFF"
"\x0\x4C\x4C\xFF\x26\x4C\x4C\xFF\x0\x26\x26\xFF\x13\x26\x26\xFF"
"\x0\xFF\xBF\xFF\x7F\xFF\xDF\xFF\x0\xA5\x7C\xFF\x52\xA5\x91\xFF"
"\x0\x7F\x5F\xFF\x3F\x7F\x6F\xFF\x0\x4C\x39\xFF\x26\x4C\x42\xFF"
"\x0\x26\x1C\xFF\x13\x26\x21\xFF\x0\xFF\x7F\xFF\x7F\xFF\xBF\xFF"
"\x0\xA5\x52\xFF\x52\xA5\x7C\xFF\x0\x7F\x3F\xFF\x3F\x7F\x5F\xFF"
"\x0\x4C\x26\xFF\x26\x4C\x39\xFF\x0\x26\x13\xFF\x13\x26\x1C\xFF"
"\x0\xFF\x3F\xFF\x7F\xFF\x9F\xFF\x0\xA5\x29\xFF\x52\xA5\x67\xFF"
"\x0\x7F\x1F\xFF\x3F\x7F\x4F\xFF\x0\x4C\x13\xFF\x26\x4C\x2F\xFF"
"\x0\x26\x9\xFF\x13\x26\x17\xFF\x0\xFF\x0\xFF\x7F\xFF\x7F\xFF"
"\x0\xA5\x0\xFF\x52\xA5\x52\xFF\x0\x7F\x0\xFF\x3F\x7F\x3F\xFF"
"\x0\x4C\x0\xFF\x26\x4C\x26\xFF\x0\x26\x0\xFF\x13\x26\x13\xFF"
"\x3F\xFF\x0\xFF\x9F\xFF\x7F\xFF\x29\xA5\x0\xFF\x67\xA5\x52\xFF"
"\x1F\x7F\x0\xFF\x4F\x7F\x3F\xFF\x13\x4C\x0\xFF\x2F\x4C\x26\xFF"
"\x9\x26\x0\xFF\x17\x26\x13\xFF\x7F\xFF\x0\xFF\xBF\xFF\x7F\xFF"
"\x52\xA5\x0\xFF\x7C\xA5\x52\xFF\x3F\x7F\x0\xFF\x5F\x7F\x3F\xFF"
"\x26\x4C\x0\xFF\x39\x4C\x26\xFF\x13\x26\x0\xFF\x1C\x26\x13\xFF"
"\xBF\xFF\x0\xFF\xDF\xFF\x7F\xFF\x7C\xA5\x0\xFF\x91\xA5\x52\xFF"
"\x5F\x7F\x0\xFF\x6F\x7F\x3F\xFF\x39\x4C\x0\xFF\x42\x4C\x26\xFF"
"\x1C\x26\x0\xFF\x21\x26\x13\xFF\xFF\xFF\x0\xFF\xFF\xFF\x7F\xFF"
"\xA5\xA5\x0\xFF\xA5\xA5\x52\xFF\x7F\x7F\x0\xFF\x7F\x7F\x3F\xFF"
"\x4C\x4C\x0\xFF\x4C\x4C\x26\xFF\x26\x26\x0\xFF\x26\x26\x13\xFF"
"\xFF\xBF\x0\xFF\xFF\xDF\x7F\xFF\xA5\x7C\x0\xFF\xA5\x91\x52\xFF"
"\x7F\x5F\x0\xFF\x7F\x6F\x3F\xFF\x4C\x39\x0\xFF\x4C\x42\x26\xFF"
"\x26\x1C\x0\xFF\x26\x21\x13\xFF\xFF\x7F\x0\xFF\xFF\xBF\x7F\xFF"
"\xA5\x52\x0\xFF\xA5\x7C\x52\xFF\x7F\x3F\x0\xFF\x7F\x5F\x3F\xFF"
"\x4C\x26\x0\xFF\x4C\x39\x26\xFF\x26\x13\x0\xFF\x26\x1C\x13\xFF"
"\xFF\x3F\x0\xFF\xFF\x9F\x7F\xFF\xA5\x29\x0\xFF\xA5\x67\x52\xFF"
"\x7F\x1F\x0\xFF\x7F\x4F\x3F\xFF\x4C\x13\x0\xFF\x4C\x2F\x26\xFF"
"\x26\x9\x0\xFF\x26\x17\x13\xFF\xFF\x0\x0\xFF\xFF\x7F\x7F\xFF"
"\xA5\x0\x0\xFF\xA5\x52\x52\xFF\x7F\x0\x0\xFF\x7F\x3F\x3F\xFF"
"\x4C\x0\x0\xFF\x4C\x26\x26\xFF\x26\x0\x0\xFF\x26\x13\x13\xFF"
"\xFF\x0\x3F\xFF\xFF\x7F\x9F\xFF\xA5\x0\x29\xFF\xA5\x52\x67\xFF"
"\x7F\x0\x1F\xFF\x7F\x3F\x4F\xFF\x4C\x0\x13\xFF\x4C\x26\x2F\xFF"
"\x26\x0\x9\xFF\x26\x13\x17\xFF\xFF\x0\x7F\xFF\xFF\x7F\xBF\xFF"
"\xA5\x0\x52\xFF\xA5\x52\x7C\xFF\x7F\x0\x3F\xFF\x7F\x3F\x5F\xFF"
"\x4C\x0\x26\xFF\x4C\x26\x39\xFF\x26\x0\x13\xFF\x26\x13\x1C\xFF"
"\xFF\x0\xBF\xFF\xFF\x7F\xDF\xFF\xA5\x0\x7C\xFF\xA5\x52\x91\xFF"
"\x7F\x0\x5F\xFF\x7F\x3F\x6F\xFF\x4C\x0\x39\xFF\x4C\x26\x42\xFF"
"\x26\x0\x1C\xFF\x26\x13\x21\xFF\xFF\x0\xFF\xFF\xFF\x7F\xFF\xFF"
"\xA5\x0\xA5\xFF\xA5\x52\xA5\xFF\x7F\x0\x7F\xFF\x7F\x3F\x7F\xFF"
"\x4C\x0\x4C\xFF\x4C\x26\x4C\xFF\x26\x0\x26\xFF\x26\x13\x26\xFF"
"\xBF\x0\xFF\xFF\xDF\x7F\xFF\xFF\x7C\x0\xA5\xFF\x91\x52\xA5\xFF"
"\x5F\x0\x7F\xFF\x6F\x3F\x7F\xFF\x39\x0\x4C\xFF\x42\x26\x4C\xFF"
"\x1C\x0\x26\xFF\x21\x13\x26\xFF\x7F\x0\xFF\xFF\xBF\x7F\xFF\xFF"
"\x52\x0\xA5\xFF\x7C\x52\xA5\xFF\x3F\x0\x7F\xFF\x5F\x3F\x7F\xFF"
"\x26\x0\x4C\xFF\x39\x26\x4C\xFF\x13\x0\x26\xFF\x1C\x13\x26\xFF"
"\x3F\x0\xFF\xFF\x9F\x7F\xFF\xFF\x29\x0\xA5\xFF\x67\x52\xA5\xFF"
"\x1F\x0\x7F\xFF\x4F\x3F\x7F\xFF\x13\x0\x4C\xFF\x2F\x26\x4C\xFF"
"\x9\x0\x26\xFF\x17\x13\x26\xFF\x0\x0\x0\xFF\x2D\x2D\x2D\xFF"
"\x5B\x5B\x5B\xFF\x89\x89\x89\xFF\xB7\xB7\xB7\xFF\xB3\xB3\xB3\xFF"
// End of "white" Acad R13c4 Palette
// Default AutoCAD "Black" R13c4 Palette
"\x0\x0\x0\xFF\x0\x0\xFF\xFF\x0\xFF\xFF\xFF\x0\xFF\x0\xFF"
"\xFF\xFF\x0\xFF\xFF\x0\x0\xFF\xFF\x0\xFF\xFF\xFF\xFF\xFF\xFF"
"\x80\x80\x80\xFF\xC0\xC0\xC0\xFF\x0\x0\xFF\xFF\x7F\x7F\xFF\xFF"
"\x0\x0\xCC\xFF\x66\x66\xCC\xFF\x0\x0\x99\xFF\x4C\x4C\x99\xFF"
"\x0\x0\x7F\xFF\x3F\x3F\x7F\xFF\x0\x0\x4C\xFF\x26\x26\x4C\xFF"
"\x0\x3F\xFF\xFF\x7F\x9F\xFF\xFF\x0\x33\xCC\xFF\x66\x7F\xCC\xFF"
"\x0\x26\x99\xFF\x4C\x5F\x99\xFF\x0\x1F\x7F\xFF\x3F\x4F\x7F\xFF"
"\x0\x13\x4C\xFF\x26\x2F\x4C\xFF\x0\x7F\xFF\xFF\x7F\xBF\xFF\xFF"
"\x0\x66\xCC\xFF\x66\x99\xCC\xFF\x0\x4C\x99\xFF\x4C\x72\x99\xFF"
"\x0\x3F\x7F\xFF\x3F\x5F\x7F\xFF\x0\x26\x4C\xFF\x26\x39\x4C\xFF"
"\x0\xBF\xFF\xFF\x7F\xDF\xFF\xFF\x0\x99\xCC\xFF\x66\xB2\xCC\xFF"
"\x0\x72\x99\xFF\x4C\x85\x99\xFF\x0\x5F\x7F\xFF\x3F\x6F\x7F\xFF"
"\x0\x39\x4C\xFF\x26\x42\x4C\xFF\x0\xFF\xFF\xFF\x7F\xFF\xFF\xFF"
"\x0\xCC\xCC\xFF\x66\xCC\xCC\xFF\x0\x99\x99\xFF\x4C\x99\x99\xFF"
"\x0\x7F\x7F\xFF\x3F\x7F\x7F\xFF\x0\x4C\x4C\xFF\x26\x4C\x4C\xFF"
"\x0\xFF\xBF\xFF\x7F\xFF\xDF\xFF\x0\xCC\x99\xFF\x66\xCC\xB2\xFF"
"\x0\x99\x72\xFF\x4C\x99\x85\xFF\x0\x7F\x5F\xFF\x3F\x7F\x6F\xFF"
"\x0\x4C\x39\xFF\x26\x4C\x42\xFF\x0\xFF\x7F\xFF\x7F\xFF\xBF\xFF"
"\x0\xCC\x66\xFF\x66\xCC\x99\xFF\x0\x99\x4C\xFF\x4C\x99\x72\xFF"
"\x0\x7F\x3F\xFF\x3F\x7F\x5F\xFF\x0\x4C\x26\xFF\x26\x4C\x39\xFF"
"\x0\xFF\x3F\xFF\x7F\xFF\x9F\xFF\x0\xCC\x33\xFF\x66\xCC\x7F\xFF"
"\x0\x99\x26\xFF\x4C\x99\x5F\xFF\x0\x7F\x1F\xFF\x3F\x7F\x4F\xFF"
"\x0\x4C\x13\xFF\x26\x4C\x2F\xFF\x0\xFF\x0\xFF\x7F\xFF\x7F\xFF"
"\x0\xCC\x0\xFF\x66\xCC\x66\xFF\x0\x99\x0\xFF\x4C\x99\x4C\xFF"
"\x0\x7F\x0\xFF\x3F\x7F\x3F\xFF\x0\x4C\x0\xFF\x26\x4C\x26\xFF"
"\x3F\xFF\x0\xFF\x9F\xFF\x7F\xFF\x33\xCC\x0\xFF\x7F\xCC\x66\xFF"
"\x26\x99\x0\xFF\x5F\x99\x4C\xFF\x1F\x7F\x0\xFF\x4F\x7F\x3F\xFF"
"\x13\x4C\x0\xFF\x2F\x4C\x26\xFF\x7F\xFF\x0\xFF\xBF\xFF\x7F\xFF"
"\x66\xCC\x0\xFF\x99\xCC\x66\xFF\x4C\x99\x0\xFF\x72\x99\x4C\xFF"
"\x3F\x7F\x0\xFF\x5F\x7F\x3F\xFF\x26\x4C\x0\xFF\x39\x4C\x26\xFF"
"\xBF\xFF\x0\xFF\xDF\xFF\x7F\xFF\x99\xCC\x0\xFF\xB2\xCC\x66\xFF"
"\x72\x99\x0\xFF\x85\x99\x4C\xFF\x5F\x7F\x0\xFF\x6F\x7F\x3F\xFF"
"\x39\x4C\x0\xFF\x42\x4C\x26\xFF\xFF\xFF\x0\xFF\xFF\xFF\x7F\xFF"
"\xCC\xCC\x0\xFF\xCC\xCC\x66\xFF\x99\x99\x0\xFF\x99\x99\x4C\xFF"
"\x7F\x7F\x0\xFF\x7F\x7F\x3F\xFF\x4C\x4C\x0\xFF\x4C\x4C\x26\xFF"
"\xFF\xBF\x0\xFF\xFF\xDF\x7F\xFF\xCC\x99\x0\xFF\xCC\xB2\x66\xFF"
"\x99\x72\x0\xFF\x99\x85\x4C\xFF\x7F\x5F\x0\xFF\x7F\x6F\x3F\xFF"
"\x4C\x39\x0\xFF\x4C\x42\x26\xFF\xFF\x7F\x0\xFF\xFF\xBF\x7F\xFF"
"\xCC\x66\x0\xFF\xCC\x99\x66\xFF\x99\x4C\x0\xFF\x99\x72\x4C\xFF"
"\x7F\x3F\x0\xFF\x7F\x5F\x3F\xFF\x4C\x26\x0\xFF\x4C\x39\x26\xFF"
"\xFF\x3F\x0\xFF\xFF\x9F\x7F\xFF\xCC\x33\x0\xFF\xCC\x7F\x66\xFF"
"\x99\x26\x0\xFF\x99\x5F\x4C\xFF\x7F\x1F\x0\xFF\x7F\x4F\x3F\xFF"
"\x4C\x13\x0\xFF\x4C\x2F\x26\xFF\xFF\x0\x0\xFF\xFF\x7F\x7F\xFF"
"\xCC\x0\x0\xFF\xCC\x66\x66\xFF\x99\x0\x0\xFF\x99\x4C\x4C\xFF"
"\x7F\x0\x0\xFF\x7F\x3F\x3F\xFF\x4C\x0\x0\xFF\x4C\x26\x26\xFF"
"\xFF\x0\x3F\xFF\xFF\x7F\x9F\xFF\xCC\x0\x33\xFF\xCC\x66\x7F\xFF"
"\x99\x0\x26\xFF\x99\x4C\x5F\xFF\x7F\x0\x1F\xFF\x7F\x3F\x4F\xFF"
"\x4C\x0\x13\xFF\x4C\x26\x2F\xFF\xFF\x0\x7F\xFF\xFF\x7F\xBF\xFF"
"\xCC\x0\x66\xFF\xCC\x66\x99\xFF\x99\x0\x4C\xFF\x99\x4C\x72\xFF"
"\x7F\x0\x3F\xFF\x7F\x3F\x5F\xFF\x4C\x0\x26\xFF\x4C\x26\x39\xFF"
"\xFF\x0\xBF\xFF\xFF\x7F\xDF\xFF\xCC\x0\x99\xFF\xCC\x66\xB2\xFF"
"\x99\x0\x72\xFF\x99\x4C\x85\xFF\x7F\x0\x5F\xFF\x7F\x3F\x6F\xFF"
"\x4C\x0\x39\xFF\x4C\x26\x42\xFF\xFF\x0\xFF\xFF\xFF\x7F\xFF\xFF"
"\xCC\x0\xCC\xFF\xCC\x66\xCC\xFF\x99\x0\x99\xFF\x99\x4C\x99\xFF"
"\x7F\x0\x7F\xFF\x7F\x3F\x7F\xFF\x4C\x0\x4C\xFF\x4C\x26\x4C\xFF"
"\xBF\x0\xFF\xFF\xDF\x7F\xFF\xFF\x99\x0\xCC\xFF\xB2\x66\xCC\xFF"
"\x72\x0\x99\xFF\x85\x4C\x99\xFF\x5F\x0\x7F\xFF\x6F\x3F\x7F\xFF"
"\x39\x0\x4C\xFF\x42\x26\x4C\xFF\x7F\x0\xFF\xFF\xBF\x7F\xFF\xFF"
"\x66\x0\xCC\xFF\x99\x66\xCC\xFF\x4C\x0\x99\xFF\x72\x4C\x99\xFF"
"\x3F\x0\x7F\xFF\x5F\x3F\x7F\xFF\x26\x0\x4C\xFF\x39\x26\x4C\xFF"
"\x3F\x0\xFF\xFF\x9F\x7F\xFF\xFF\x33\x0\xCC\xFF\x7F\x66\xCC\xFF"
"\x26\x0\x99\xFF\x5F\x4C\x99\xFF\x1F\x0\x7F\xFF\x4F\x3F\x7F\xFF"
"\x13\x0\x4C\xFF\x2F\x26\x4C\xFF\x33\x33\x33\xFF\x5B\x5B\x5B\xFF"
"\x84\x84\x84\xFF\xAD\xAD\xAD\xFF\xD6\xD6\xD6\xFF\xFF\xFF\xFF\xFF"
// End of "Black" Acad R13c4 Palette
;  // That's all folks

// Note: when using the new ZLIB based compression scheme (DWF files of version
// 00.39 or greater), the pre-loaded
// history data isn't the same as it is for the older DWF files.  In the
// new ZLIB code we don't pre-load the old Autocad black and white colormaps
// (since nobody uses them or liked them very much).  By not storing them,
// we make sure we don't overflow the ZLIB history buffer.
// The constant below computes how much of the preload data we *don't* store:

// The actuall define that is commented out below is found in LZDEFS.H, if you
// ever need to change it, go there.
// #define WD_PORTION_OF_PRELOAD_DATA_NOT_USED_FOR_ZLIB    (2 * 256 * 4)   /* 2 Colormaps of 256 rgba colors */

// Note: new preload data should be added to the beginning of this array
// in order to allow us to read older files (compression offsets are relative
//  to the end of the history buffer).


extern int const WD_History_Buffer_Preload_Size = sizeof(WD_History_Buffer_Preload);
