/*
 Copyright (C) 2006-2007  Patrik Weiskircher
 
 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, 
 MA 02110-1301, USA.
 */

#import <Cocoa/Cocoa.h>
#import "MusicServerClient.h"
#import "AppleRemote.h"

@class PreferencesController, PlayListController, PWWindow;
@class LicenseController, PWVolumeSlider, LibraryController, PWTableView, PWMusicSearchField;
@class InfoAreaController, UpdateDatabaseController, UnifiedToolbar, UnifiedToolbarItem;
@class PlayListFilesController, SongInfoController;

extern NSString *tPlayControlItemIdentifier;
extern NSString *tStopItemIdentifier;
extern NSString *tSearchField;

@interface WindowController : NSObject {
	// controller
	IBOutlet PlayListController *mPlaylistController;
	IBOutlet PreferencesController *mPreferencesController;	
	IBOutlet LicenseController *mLicenseController;
	IBOutlet InfoAreaController *mInfoAreaController;
	LibraryController *mLibraryController;
	UpdateDatabaseController *mUpdateDatabaseController;
	PlayListFilesController *mPlayListFilesController;
		
	// UI
	IBOutlet PWWindow *mWindow;
	IBOutlet PWTableView *mPlaylist;
	IBOutlet NSButton *mLibraryButton;
	IBOutlet NSMenuItem *mConnectItem;
	IBOutlet NSMenuItem *mDisconnectItem;
	IBOutlet NSMenuItem *mShuffleItem;
	IBOutlet NSMenuItem *mRepeatItem;

	// Toolbar
	UnifiedToolbar *mToolbar;
	UnifiedToolbarItem *mPlayerItem, *mStopItem;
	NSMutableDictionary *mToolbarItems;
	PWVolumeSlider *mVolumeSlider;
	PWMusicSearchField *mMusicSearch;
	
	// autoreconnect stuff
	NSTimer *mAutoreconnectTimer;
	BOOL mDisableAutoreconnectOnce;
	
	// MPD Status Information
	id mClient;
	int mCurrentState;
	
	// DO object
	NSConnection *mConnectionToMpdClient;
	
	// authentication
	IBOutlet NSPanel *mAuthenticationPanel;
	IBOutlet NSButton *mCancelButton, *mAuthenticateButton;
	IBOutlet NSTextField *mAuthenticationDescription;
	IBOutlet NSButton *mAuthenticationSavePassword;
	IBOutlet NSSecureTextField *mAuthenticationPassword;
	
	BOOL mPausedOnSleep;
	
	BOOL mAppleRemoteButtonHeld;
	
	RemoteControl *mAppleRemote;
}

+ (id) instance;

- (void)setMusicClient:(id)inClient;
- (id)musicClient;

- (int) currentPlayerState;

- (PreferencesController *) preferences;
- (PlayListController *) playlistController;

- (NSWindow *)window;
- (NSString *)applicationSupportFolder;

- (IBAction) preferencesClicked:(id)sender;
- (IBAction) authenticationButtonPressed:(id)sender;
- (IBAction) togglePlayPause:(id)sender;
- (IBAction) nextSong:(id)sender;
- (IBAction) previousSong:(id)sender;
- (IBAction) nextAlbum:(id)sender;
- (IBAction) prevAlbum:(id)sender;	
- (IBAction) stop:(id)sender;
- (IBAction) showPlayerWindow:(id)sender;
- (IBAction) showLicense:(id)sender;
- (IBAction) showLibrary:(id)sender;
- (IBAction) showUpdateDatabase:(id)sender;
- (IBAction) updateCompleteDatabase:(id)sender;
- (IBAction) deleteSelectedSongs:(id)sender;
- (IBAction) seekSliderChanged:(id)sender;
- (IBAction) connect:(id)sender;
- (IBAction) disconnect:(id)sender;
- (IBAction) toggleShuffle:(id)sender;
- (IBAction) toggleRepeat:(id)sender;
- (IBAction) find:(id)sender;
- (IBAction) scrollToCurrentSong:(id)sender;
- (IBAction) toggleDrawer:(id)sender;
- (IBAction) saveCurrentPlaylist:(id)sender;
- (IBAction) randomizePlaylist:(id)sender;
- (IBAction) increaseVolume:(id)sender;
- (IBAction) decreaseVolume:(id)sender;
- (IBAction) getInfo:(id)sender;
- (IBAction) getInfoOnKeyWindow:(id)sender;
- (IBAction) detectCompilations:(id)sender;

- (void)getSystemVersionMajor:(unsigned *)major minor:(unsigned *)minor bugFix:(unsigned *)bugFix;
@end