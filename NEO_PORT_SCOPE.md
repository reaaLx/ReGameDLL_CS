# Counter-Strike NEO port: scope

Goal: a Windows server DLL built on ReGameDLL_CS that reproduces the gameplay features of Counter-Strike NEO 2 (Namco, 2003–2010), so it runs on a retail Counter-Strike 1.6 install with a stock Steam client.

## Target build

- NEO server game DLL: `cs_i486.so` (Linux, GCC 3.2.2, DWARF present), Namco build path `/home/arcade/devel-yuki/contents2/csneo2/linux`.
- Engine interface: NEO's `enginefuncs_t` has 165 entries (660 bytes). Retail has 155 (620 bytes). The 10 Namco entries are listed below.
- Client: stock Steam Counter-Strike 1.6 client (Dec 2023 build). Namco's own client DLL is not used.

## In scope

| Area | Items |
|---|---|
| Engine interface | Extend the copied table to 165 entries. Implement the Namco functions locally: `pfnSetPlaceData`, `pfnSetNEO2Rule`, `pfnGetNEO2Rule`, `pfnTakaSetNumChangeLevel`, `pfnTakaGetNextLevelName`, `pfnCheckParm`, `pfnGetRateLevel`, `pfnPrecachePlayerModel`, `pfnGetPlayerModelFileName`, `pfnGetSaveDir`. |
| Rules | NEO 2 rule modes (`CHalfLifeMultiplay::CheckNEO2Rule`, `InitializeNEO2Rule`, `SetNEO2RuleMode`), team names CSF/NEO, bomb-defusal-only mode. |
| Rating | `CCRM`: per-player and per-clan rate, first-half and second-half team kill/death counters, `CRMGAME_*` events. Local storage, not a server. |
| Game records | `grec` event recording (buys, C4 plant/defuse/explode, team results). Local output only. |
| Bots | `bot_godeye`, `bot_rubberband`, `bot_tactics`, `CMtBotTacticalBuy` with separate CSF and NEO buy tables. |
| Training | `training_*` modules (about 15), starting with the `tr_1` map (`trainmap "tr_1"` in `liblist.gam`). |
| Popups | `CNEO2Popup`, `CNEO2BeginnerModeEntity`. |
| Intermission and career | `CInfoIntermission`, NEO career-task additions. |
| User messages | The 15 NEO-only messages are translated to standard messages where possible, or skipped. See the list below. |

## Out of scope

- **Arcade hardware:** HASP dongle code, card reader (`SYS_CARD`, `mucard_main`, `DB::CardCheck`), cabinet lamps (`nsLamp`, `pcb_lampOn`), and the `-ledzonemode` flag.
- **LED ZONE networking:** Namco master server, clan database (`dbStore*`, `CClan*`), the rating server, the Steam auth server, and the `CIPRateLimit` layer.
- **Client-side Namco code:** `client.dll` is not used. HUD visuals that depended on it are dropped unless rebuilt later as a separate project.
- **Original Namco assets** are not redistributed. The port uses the retail CS install for assets.

## NEO-only user messages (15)

Candidates, from a name comparison that isn't fully reliable:
`CreatePopup`, `DeletePopup`, `PlayLamp`, `EngineMenu`, `HudScene`, `PrintCRM`, `PlayerInfo`, `GameRule`, `CanPayPoint`, `SendMsg`, `PlaceName`, `Damage2`, `CanBuy`, `Camper`, `GoodJob`.

Each needs a decision: translate to a standard message, or skip. Plan is to decide during the client-compatibility check.

## Clean-room rules

- Write new code from NEO's observed behaviour, debug symbol names and the headers exported from the DWARF. Do not transcribe disassembly.
- Namco's binaries and assets are not committed to the repository.
- Keep a note in each feature's commit of which NEO symbols it corresponds to.

## Milestones

1. Windows build of unmodified ReGameDLL_CS, tested on the retail CS install with the stock client.
2. Engine interface extended to 165 entries, with local Namco functions.
3. DWARF header export for NEO-specific types.
4. Rules, then rating, records, bots, training, popups, intermission.
5. User-message decisions and client smoke test.
6. LAN playtest.
